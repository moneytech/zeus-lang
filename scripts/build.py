import os, subprocess, pprint, re, types
from pathlib import Path

def sorted_versions(l):
    return sorted(l, key=lambda s: [int(u) for u in s.split('.')])

def substitute(command, *args):
    transposed_command = str(command)
    argument_iterator = 1
    for arg in args:
        if type(arg) is list:
            list_arg = ''
            if len(arg) > 0:
                for a in arg:
                    list_arg = list_arg + ' ' + str(a)
                transposed_command = transposed_command.replace('$' + str(argument_iterator), list_arg)
        else:
            transposed_command = transposed_command.replace('$' + str(argument_iterator), str(arg))
        argument_iterator += 1
    return re.sub('$.', '', transposed_command)

def shell_execute(command):
    print('Executing command: ' + command)
    return subprocess.run(command, stdout=subprocess.PIPE).stdout

def compile_unit(src, out, flags='-g'):
    src_name, src_ext = os.path.splitext(src)
    if src_ext == '.c':
        out_name, out_ext = os.path.splitext(out)
        shell_execute(substitute('gcc -c $1 -o $2.o $3', src, out_name, flags))
        return Path(out_name + '.o')

def compile_executable(path, objects, flags='-Wall -g'):
    shell_execute(substitute('gcc $3 $2 -o $1.exe', path, objects, flags))
    return Path(path)

def create_directory(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)

def compile_library(path, objects, flags='rcs'):
    shell_execute(substitute('ar $3 $1.a $2', path, objects, flags))
    return Path(path)

def flatten(list):
    return [item for sublist in list for item in sublist]

def dirs_in(path, recursive=False):
    result = []
    dirs = [x for x in Path(path).iterdir() if x.is_dir()]
    in_subdirs = []
    if recursive:
        for dir in dirs:
            dirs_in_subdir = dirs_in(dir, recursive)
            for d in dirs_in_subdir:
                if type(d) is not list:
                    in_subdirs.append(d)
    if len(in_subdirs) > 0:
        result = flatten([dirs, in_subdirs])
    else:
        result = dirs
    return result

def files_in(path, recursive=False):
    result = []
    files = [x for x in Path(path).iterdir() if x.is_file()]
    in_subdirs = []
    if recursive:
        dirs = dirs_in(path, recursive)
        for dir in dirs:
            in_subdirs.append(files_in(dir, recursive))
    if len(in_subdirs) > 0:
        result = flatten([files, in_subdirs])
    else:
        result = files
    return result

def path_split_head(path):
    path_obj = Path(path)
    if len(path_obj.parts) > 1:
        return Path(*path_obj.parts[:1]), Path(*path_obj.parts[1:])
    else:
        return path

def path_split_tail(path):
    path_obj = Path(path)
    if len(path_obj.parts) > 1:
        return Path(*path_obj.parts[:-1]), Path(*path_obj.parts[-1:])
    else:
        return path

def path_head(path):
    head, body = path_split_head(path)
    return head

def path_headless(path):
    head, body = path_split_head(path)
    return body

def path_tail(path):
    body, tail = path_split_tail(path)
    return tail

def path_tailless(path):
    body, tail = path_split_tail(path)
    return body

def mirror(src, out, remove_head=True):
    src_path = Path(src)
    src_dirs = dirs_in(src_path, True)
    out_dirs = []
    for dir in src_dirs:
        if type(dir) is not list:
            dir_path = Path(dir)
            if dir_path.is_dir():
                out_path = Path(out)
                if remove_head:
                    out_headless = path_headless(dir_path)
                    out_path = out_path / out_headless
                create_directory(out_path)
                out_dirs.append(out_path)
    return src_dirs, out_dirs


if __name__ == '__main__':
    mirror_in, mirror_out = mirror('src/zeus', 'build/obj')
    mirror_in, mirror_out = mirror('src/', 'build/obj')
    mirror_in, mirror_out = mirror('src/zeus', 'build/bin')
    mirror_in, mirror_out = mirror('src/targets', 'build/bin')
    pprint.pprint(mirror_in)
    pprint.pprint(mirror_out)
