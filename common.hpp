#pragma once

// Start of configurable properties
#define BOARD_ROWS 10
#define BOARD_COLUMNS 10
#define FEATURES_LENGTH (int)BOARD_ROWS*BOARD_COLUMNS/4
#define SINGLE_FEATURES_LENGTH (int)(FEATURES_LENGTH / 2)
// End of configurable properties

#define BOARD_CELLS BOARD_ROWS*BOARD_COLUMNS