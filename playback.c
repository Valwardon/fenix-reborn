#include <stdio.h>
#include "macro.h"

int main() {
    Macro* macro = create_macro("macro.txt", 0, NULL);
    if (macro == NULL) {
        fprintf(stderr, "Error: could not create macro\n");
        return 1;
    }
    if (macro_init() != 0) {
        fprintf(stderr, "Error: could not initialize macro system\n");
        delete_macro(macro);
        return 1;
    }
    if (macro_perform(macro) != 0) {
        fprintf(stderr, "Error: could not perform macro\n");
        macro_cleanup();
        delete_macro(macro);
        return 1;
    }
    macro_cleanup();
    delete_macro(macro);
    return 0;
}