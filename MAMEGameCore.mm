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

#import "MAMEGameCore.h"
#import <OpenEmuBase/OERingBuffer.h>
#import "OEGBASystemResponderClient.h"
#import <OpenGL/gl.h>

@interface MAMEGameCore () <OEArcadeSystemResponderClient>
{
    uint32_t *videoBuffer;
    int videoWidth, videoHeight;
    int16_t pad[1][10];
    NSString *romName;
    double sampleRate;
    double frameInterval;
}

@end

MAMEGameCore *current;
@implementation MAMEGameCore

- (oneway void)didPushArcadeButton:(OEArcadeButton)button forPlayer:(NSUInteger)player;
{
    //pad[player-1][ArcadeEmulatorValues[button]] = 1;
}

- (oneway void)didReleaseArcadeButton:(OEArcadeButton)button forPlayer:(NSUInteger)player;
{
    //pad[player-1][ArcadeEmulatorValues[button]] = 0;
}

- (id)init
{
    if((self = [super init]))
    {
        videoBuffer = (uint32_t *)malloc(640 * 480 * 4);
    }
	
	current = self;

	return self;
}

#pragma mark Exectuion

- (void)executeFrame
{
    [self executeFrameSkippingFrame:NO];
}

- (void)executeFrameSkippingFrame:(BOOL)skip
{
    
}

- (BOOL)loadFileAtPath:(NSString *)path
{
	memset(pad, 0, sizeof(int16_t) * 10);
    romName = [path copy];
    
    return NO;
}

#pragma mark Video
- (const void *)videoBuffer
{
    return videoBuffer;
}

- (OEIntRect)screenRect
{
    return OEIntRectMake(0, 0, videoWidth, videoHeight);
}

- (OEIntSize)bufferSize
{
    return OEIntSizeMake(640, 480);
}

- (OEIntSize)aspectSize
{
    return OEIntSizeMake(4, 3);
}

- (void)setupEmulation
{
}

- (void)resetEmulation
{
}

- (void)stopEmulation
{
    [super stopEmulation];
}

- (void)dealloc
{
    free(videoBuffer);
}

- (GLenum)pixelFormat
{
    return GL_BGRA;
}

- (GLenum)pixelType
{
    return GL_UNSIGNED_INT_8_8_8_8_REV;
}

- (GLenum)internalPixelFormat
{
    return GL_RGB8;
}

- (double)audioSampleRate
{
    return sampleRate ? sampleRate : 48000;
}

- (NSTimeInterval)frameInterval
{
    return frameInterval ? frameInterval : 60;
}

- (NSUInteger)channelCount
{
    return 2;
}

- (BOOL)saveStateToFileAtPath:(NSString *)fileName
{
    return NO;
}

- (BOOL)loadStateFromFileAtPath:(NSString *)fileName
{
    return NO;
}

@end
