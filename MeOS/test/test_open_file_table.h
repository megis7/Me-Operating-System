#ifndef TEST_OPEN_FILE_TABLE_H_28102017
#define TEST_OPEN_FILE_TABLE_H_28102017

#include "../open_file_table.h"
#include "test_base.h"

bool test_open_file_table_open();
bool test_vfs_open_file();
bool test_open_file();
bool test_read_file();
bool test_read_file_cached();
bool test_write_file_cached();
bool test_sync_file();
bool test_write_with_dirty();

#endif
