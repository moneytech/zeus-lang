from BuildTool.BuildPath import BuildPath
from BuildTool.BuildShell import BuildShell
from BuildTool.Crawler import Crawler, CrawlStrategy, CrawlAction
from pathlib import Path

shell = BuildShell()

def compile_unit(src, out, flags='-g'):
    src_name, src_ext = BuildPath(src).split_filename()
    if src_ext == '.c':
        out_name, out_ext = BuildPath(out).split_filename()
        shell.execute_command(shell.substitute('gcc -c $1 -o $2.o $3', src, out_name, flags))
        return Path(out_name + '.o')

def compile_executable(path, objects, flags='-Wall -g'):
    shell.execute_command(shell.substitute('gcc $3 $2 -o $1.exe', path, objects, flags))
    return Path(path)

def compile_library(path, objects, flags='rcs'):
    shell.execute_command(shell.substitute('ar $3 $1.a $2', path, objects, flags))
    return Path(path)

def mirror(src, out, remove_head=True):
    src_crawler = Crawler(src, CrawlStrategy.RECURSIVE, CrawlAction.DIRECTORIES)
    src_crawler.crawl()
    src_dirs = src_crawler.directories()
    out_dirs = []
    for dir in src_dirs:
        out_path = Path(out)
        if remove_head:
            out_path = out_path / BuildPath(BuildPath(dir).headless()).headless()
        BuildPath(out_path).create()
        out_dirs.append(out_path)
    return src_dirs, out_dirs


if __name__ == '__main__':
    mirror('../src', '../build')
