#ifndef FILE_H_17032017
#define FILE_H_17032017

#include "types.h"
#include "vfs.h"
#include "open_file_table.h"
#include "page_cache.h"


enum FILE_OPEN_FLAGS
{
	O_NOCACHE	 = 1,			// when set, the driver does not use the page cache. Every read and write offset and count must be aligned as specified by the driver.
	O_CACHE_ONLY = 2			// when set, any data transfered from a mass storage media to the page cache, remain there and are not copied to the requested address (address is ignored).
};

enum FILE_ERROR
{
	FILE_NONE,
	FILE_GFD_NOT_FOUND,
	FILE_BAD_GFD,
	FILE_CAPABILITIES_ERROR,
	FILE_READ_ACCESS_DENIED,
	FILE_WRITE_ACCESS_DENIED,
	FILE_UNALIGED_ADDRESS,
	FILE_BIG_REQUEST,
	FILE_FAR_START
};

	/* Defines the standard file io API */

	// opens a file and associates a local file descriptor with it
	error_t open_file(char* path, uint32* fd, uint32 capabilities);

	// opens a file indicated by the given node and associates a local and a global file descriptor with it
	error_t open_file_by_node(vfs_node* node, uint32* fd, uint32 capabilities);

	//error_t close_file(uint32 gfd);

	// reads the file, given its global file descriptor, to the given buffer
	size_t read_file(uint32 fd, uint32 start, size_t count, virtual_addr buffer);

	size_t read_file_global(uint32 gfd, uint32 start, size_t count, virtual_addr buffer, uint32 capabilities);

	// writes to the file, given its global file descriptor, from the given buffer
	size_t write_file(uint32 fd, uint32 start, size_t count, virtual_addr buffer);

	size_t write_file_global(uint32 gfd, uint32 start, size_t count, virtual_addr buffer, uint32 capabilities);

	// syncs the file, given its global file descriptor
	error_t sync_file(uint32 fd, uint32 start_page, uint32 end_page);

#endif