#include <stdlib.h>
#include <stdio.h>
#include <Zeus.h>
#include <core/system/ZeusPlatform.h>

int main(int argc, char **argv) {
  struct ZeusPlatform * platform = ZeusPlatform_create();
  printf("%s\n", OS_NAME(platform));
  printf("%s\n", OS_PATH_SEPARATOR(platform));
  printf("%s\n", OS_PATH_DELIMITER(platform));
  printf("%s\n", OS_LINE_ENDING(platform));
  return EXIT_SUCCESS;
}
