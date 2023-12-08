
#include "features/keyswapper.h"

void keyswapper(keyrecord_t *record, uint16_t keycode, uint16_t newcode) {
    // we no longer need this code so unregister it
    unregister_code(keycode);
    if (record->event.pressed) {
        // press the replacement key
        register_code(newcode);
    } else {
        // release the replacement key
        unregister_code(newcode);
    }
}
