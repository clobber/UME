/*
 Copyright (c) 2013, OpenEmu Team


 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//#include "osdepend.h"
//#include "render.h"
#include "unicode.h"
//#import "osd_osx.h"
#import <Foundation/Foundation.h>

#include <unistd.h>
#include <mach/mach.h>
//#include "sdlos.h" //??
#include "osdcore.h"
#if 0
static void osd_set_use_autorelease(BOOL use_autorelease);
static inline NSAutoreleasePool * allocPool();
static inline void releasePool(NSAutoreleasePool * pool);

static BOOL sUseAutorelease = YES;

void osx_osd_set_use_autorelease(BOOL use_autorelease)
{
    sUseAutorelease = use_autorelease;
}

static inline NSAutoreleasePool * allocPool()
{
    if (sUseAutorelease)
        return [[NSAutoreleasePool alloc] init];
    else
        return nil;
}

static inline void releasePool(NSAutoreleasePool * pool)
{
    [pool release];
}

static BOOL sInApp = NO;
static BOOL sInitialized = NO;

void osx_osd_core_set_in_app(BOOL in_app)
{
    sInApp = in_app;
}

void osx_osd_core_init(void)
{
    if (!sInitialized)
    {
        // There's no bundle/Info.plist to set the default log level
        if (!sInApp)
            [NSObject setDefaultJRLogLevel: JRLogLevel_Error];
        sInitialized = YES;
    }
}

#define PROLOG() \
    NSAutoreleasePool * pool = allocPool(); \

#define EPILOG() \
    releasePool(pool); \
    pool = nil;

/******************************************************************************

    Locking

******************************************************************************/

typedef NSRecursiveLock MameLock;
// typedef NSLock MameLock;
#undef DEBUG_INSTRUMENTED

osd_lock * osd_lock_alloc(void)
{
    PROLOG();
    MameLock * lock = [[MameLock alloc] init];
    EPILOG();
    return (osd_lock *) lock;
}

void osd_lock_acquire(osd_lock * mame_lock)
{
    PROLOG();
    MameLock * lock = (MameLock *) mame_lock;
#ifdef DEBUG_INSTRUMENTED
    chudRecordSignPost(MameLockAcquire, chudPointSignPost, lock, 0, 0, 0);
#endif
    //NSLog(@"osd_lock_acquire (will): %p\n", lock);
    [lock lock];
    //NSLog(@"osd_lock_acquire  (did): %p\n", lock);
    EPILOG();
}

int osd_lock_try(osd_lock * mame_lock)
{
    PROLOG();
    MameLock * lock = (MameLock *) mame_lock;
#ifdef DEBUG_INSTRUMENTED
    chudRecordSignPost(MameLockTry, chudPointSignPost, lock, 0, 0, 0);
#endif
    //NSLog(@"osd_lock_try (will): %p\n", lock);
    int result = [lock tryLock];
    //NSLog(@"osd_lock_try  (did): %p = %d\n", lock, result);
    EPILOG();
    return result;
}

void osd_lock_release(osd_lock * mame_lock)
{
    PROLOG();
    MameLock * lock = (MameLock *) mame_lock;
#ifdef DEBUG_INSTRUMENTED
    chudRecordSignPost(MameLockRelease, chudPointSignPost, lock, 0, 0, 0);
#endif
    //NSLog(@"osd_lock_release (will): %p\n", lock);
    [lock unlock];
    //NSLog(@"osd_lock_release  (did): %p\n", lock);
    EPILOG();
}

void osd_lock_free(osd_lock * mame_lock)
{
    PROLOG();
    MameLock * lock = (MameLock *) mame_lock;
    [lock release];
    EPILOG();
}


/******************************************************************************

    Timing

******************************************************************************/

static MameTimingController * sTimingController;

void osd_set_timing_controller(MameTimingController * timingController)
{
    sTimingController = timingController;
}

osd_ticks_t osd_ticks(void)
{
    PROLOG();
    osd_ticks_t result =  [sTimingController osd_ticks];
    EPILOG();
    return result;
}

osd_ticks_t osd_ticks_per_second(void)
{
    PROLOG();
    osd_ticks_t result = [sTimingController osd_ticks_per_second];
    EPILOG();
    return result;
}

osd_ticks_t osd_profiling_ticks(void)
{
    PROLOG();
    osd_ticks_t result = [sTimingController osd_profiling_ticks];
    EPILOG();
    return result;
}

void osd_sleep(osd_ticks_t duration)
{
#if 1
    UINT32 msec;
    
    // convert to milliseconds, rounding down
    msec = (UINT32)(duration * 1000 / osd_ticks_per_second());
    
    // only sleep if at least 2 full milliseconds
    if (msec >= 2)
    {
        // take a couple of msecs off the top for good measure
        msec -= 2;
        usleep(msec*1000);
    }
#endif
}

/******************************************************************************

    File I/O

******************************************************************************/

static MameFileManager * sFileManager = nil;

void osd_set_file_manager(MameFileManager * fileManager)
{
    sFileManager = fileManager;
}

file_error osd_open(const char *path, UINT32 openflags, osd_file **file,
                    UINT64 *filesize)
{
    PROLOG();
    MameFileManager * manager = [MameFileManager defaultFileManager];
    file_error result = [manager osd_open: path
                                    flags: openflags
                                     file: file
                                 filesize: filesize];
    EPILOG();
    return result;
}

file_error osd_close(osd_file *file)
{
    PROLOG();
    MameFileManager * manager = [MameFileManager defaultFileManager];
    file_error result = [manager osd_close: file];
    EPILOG();
    return result;
}


file_error osd_read(osd_file *file, void *buffer, UINT64 offset,
                    UINT32 length, UINT32 *actual)
{
    PROLOG();
    MameFileManager * manager = [MameFileManager defaultFileManager];
    file_error result =  [manager osd_read: file
                                    buffer: buffer
                                    offset: offset
                                    length: length
                                    actual: actual];
    EPILOG();
    return result;
}

file_error osd_write(osd_file *file, const void *buffer, UINT64 offset,
                     UINT32 length, UINT32 *actual)
{
    PROLOG();
    MameFileManager * manager = [MameFileManager defaultFileManager];
    file_error result = [manager osd_write: file
                                    buffer: buffer
                                    offset: offset
                                    length: length
                                    actual: actual];
    EPILOG();
    return result;
}

file_error osd_rmfile(const char *filename)
{
    PROLOG();
    MameFileManager * manager = [MameFileManager defaultFileManager];
    file_error result = [manager osd_rmfile: filename];
    EPILOG();
    return result;
}

int osd_is_absolute_path(const char *path)
{
    PROLOG();
    MameFileManager * manager = [MameFileManager defaultFileManager];
    int result = [manager osd_is_absolute_path: path];
    EPILOG();
    return result;
}
#endif
//void *osd_malloc(size_t size)
//{
//    return malloc(size);
//}
//
//void osd_free(void *ptr)
//{
//    free(ptr);
//}

/***************************************************************************
MISCELLANEOUS INTERFACES
***************************************************************************/


void *osd_alloc_executable(size_t size)
{
    void * ptr = (void *) malloc(size);
#if 0
    printf("osd_alloc_executable(%d [0x%08x]) = 0x%08x - 0x%08x\n", size, size,
           ptr, ((uint8_t *) ptr) + size);
#endif
    return ptr;
}

void osd_free_executable(void *ptr, size_t size)
{
    free(ptr);
}

void osd_break_into_debugger(const char *message)
{
}


//============================================================
//  osd_uchar_from_osdchar
//============================================================

int osd_uchar_from_osdchar(unicode_char *uchar, const char *osdchar, size_t count)
{
    wchar_t wch;
    
    count = mbstowcs(&wch, (char *)osdchar, 1);
    if (count != -1)
        *uchar = wch;
    else
        *uchar = 0;
    
    return count;
}

//============================================================
//  osd_get_clipboard_text
//============================================================

char *osd_get_clipboard_text(void)
{
	char *result = NULL;
    
	return result;
}

//============================================================
//  osd_num_processors
//============================================================

int osd_num_processors(void)
{
	int processors = 1;
    
	struct host_basic_info host_basic_info;
	unsigned int count;
	kern_return_t r;
	mach_port_t my_mach_host_self;
    
	count = HOST_BASIC_INFO_COUNT;
	my_mach_host_self = mach_host_self();
	if ( ( r = host_info(my_mach_host_self, HOST_BASIC_INFO, (host_info_t)(&host_basic_info), &count)) == KERN_SUCCESS )
	{
		processors = host_basic_info.avail_cpus;
	}
	mach_port_deallocate(mach_task_self(), my_mach_host_self);
    
	return processors;
}

//============================================================
//  osd_getenv
//============================================================

char *osd_getenv(const char *name)
{
	return getenv(name);
}


//============================================================
//  osd_wait_for_debugger
//============================================================
//void osd_wait_for_debugger(const device_config *device, int firststop)
//void osd_wait_for_debugger(running_device *device, int firststop)
//{
//}

//============================================================
//  osd_get_volume_name
//============================================================

const char *osd_get_volume_name(int idx)
{
	if (idx!=0) return NULL;
	return "/";
}

//============================================================
//  osd_stat
//============================================================

osd_directory_entry *osd_stat(const char *path)
{
	int err;
	osd_directory_entry *result = NULL;
#if defined(SDLMAME_DARWIN) || defined(SDLMAME_NO64BITIO)
	//struct stat st;
#else
	//struct stat64 st;
#endif
    
#if defined(SDLMAME_DARWIN) || defined(SDLMAME_NO64BITIO)
	//err = stat(path, &st);
#else
	//err = stat64(path, &st);
#endif
    
	if( err == -1) return NULL;
    
	// create an osd_directory_entry; be sure to make sure that the caller can
	// free all resources by just freeing the resulting osd_directory_entry
	result = (osd_directory_entry *) osd_malloc(sizeof(*result) + strlen(path) + 1);
	strcpy(((char *) result) + sizeof(*result), path);
	result->name = ((char *) result) + sizeof(*result);
	//result->type = S_ISDIR(st.st_mode) ? ENTTYPE_DIR : ENTTYPE_FILE;
	//result->size = (UINT64)st.st_size;
    
	return result;
}

//============================================================
//  osd_get_full_path
//============================================================

file_error osd_get_full_path(char **dst, const char *path)
{
	file_error err;
	char path_buffer[512];
    
	err = FILERR_NONE;
    
	if (getcwd(path_buffer, 511) == NULL)
	{
		printf("osd_get_full_path: failed!\n");
		err = FILERR_FAILURE;
	}
	else
	{
		*dst = (char *)osd_malloc(strlen(path_buffer)+strlen(path)+3);
        
		// if it's already a full path, just pass it through
		if (path[0] == '/')
		{
			strcpy(*dst, path);
		}
		else
		{
			sprintf(*dst, "%s%s%s", path_buffer, PATH_SEPARATOR, path);
		}
	}
    
	return err;
}


//============================================================
//  osd_init_debugger
//============================================================
//void osd_init_debugger(running_machine *machine)
//{
//}

//============================================================
//  osd_malloc
//============================================================

void *osd_malloc(size_t size)
{
#ifndef MALLOC_DEBUG
	return malloc(size);
#else
#error "MALLOC_DEBUG not yet supported"
#endif
}


//============================================================
//  osd_malloc_array
//============================================================

void *osd_malloc_array(size_t size)
{
#ifndef MALLOC_DEBUG
	return malloc(size);
#else
#error "MALLOC_DEBUG not yet supported"
#endif
}


//============================================================
//  osd_free
//============================================================

void osd_free(void *ptr)
{
#ifndef MALLOC_DEBUG
	free(ptr);
#else
#error "MALLOC_DEBUG not yet supported"
#endif
}
