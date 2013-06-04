//
//  AVPlayerController.h
//  AVPlayer
//
//  Created by apple on 13-5-24.
//  Copyright (c) 2013年 iMoreApp Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVMovieGLView.h"

typedef enum {
    
    kAVPlayerStateInitialized=0,
    kAVPlayerStatePlaying,
    kAVPlayerStatePaused,
    kAVPlayerStateFinishedPlayback,
    kAVPlayerStateStoped,
    
    kAVPlayerStateUnknown=0xff
    
} AVPlayerState;


@protocol AVPlayerControllerDelegate;

@interface AVPlayerController : NSObject

@property (nonatomic, readonly) NSString *moviePath;
@property (nonatomic, assign) id <AVPlayerControllerDelegate> delegate;
@property (nonatomic, assign) BOOL shouldAutoPlay;

// Format second to human readable time string
+ (NSString *)formatTimeInterval:(CGFloat)seconds isLeft:(BOOL)isLeft;

/*
 * Init AVPlayerController object.
 * @view - UIView for rendering video image.
 * @If failed, return nil, otherwise return initialized AVPlayerController instance.
 */
- (id)initWithVideoContainerView:(AVMovieGLView *)view;

/*
 * Open media file at path.
 * @path - path to media file.
 * @If failed, return NO, otherwise return YES.
 */
- (BOOL)openMedia:(NSString *)path onFinishedHandler:(void (^)(BOOL))handler;

/*
 * Is movie file from network?
 * @If movie file from network return YES, otherwise return NO.
 */
- (BOOL)isNetworkFile;

/*
 * Enter or exit full screen mode.
 * @enter - YES to enter, NO to exit.
 * @This function does not return a value.
 */
- (void)fullScreen:(BOOL)enter;

/*
 * Determine AVPlayer whether or not is in full screen mode.
 * @If it is in full screen mode, return YES, otherwise return NO.
 */
- (BOOL)isFullscreen;

/*
 * Has video or audio stream.
 * @If media has video or audio stream this function return YES, otherwise return NO.
 */
- (BOOL)hasVideo;
- (BOOL)hasAudio;


/*
 * Query video frame size.
 * @This function return a CGSize value.
 */
- (CGSize)videoFrameSize;

/*
 * Query AVPlayer current state.
 * @This function return AVPlayer current state info.
 */
- (AVPlayerState)playerState;

/*
 * Query media total duration.
 * @This function return media total duration info.
 */
- (NSTimeInterval)duration;

/*
 * Query AVPlayer current playback time.
 * @This function return current playback time info.
 */
- (NSTimeInterval)currentTime;

/*
 * Start playback.
 * @fact - playback start position, 0~1.0f
 * @If failed, return NO, otherwise return YES.
 */
- (BOOL)play:(double)fact;

/*
 * Fast forward.
 * @This function does not return a value.
 */
- (void)fastforward;

/*
 * Fast backward.
 * @This function does not return a value.
 */
- (void)fastbackward;

/*
 * Pause playback.
 * @This function does not return a value.
 */
- (void)pause;

/*
 * Resume playback.
 * @This function does not return a value.
 */
- (void)resume;

/*
 * Stop playback.
 * @This function does not return a value.
 */
- (void)stop;

/*
 * Seek to position.
 * @fact - 0~1.0f
 * @This function does not return a value.
 */
- (void)seekto:(double)fact;

/*
 * Get real frame rate.
 * @This function return real frame rate.
 */
- (int)framerate;

/*
 * Get real bit rate.
 * @This function return real bit rate.
 */
- (int)bitrate;

@end


@protocol AVPlayerControllerDelegate

@optional

// AVPlayer state was changed
- (void)AVPlayerControllerDidStateChange:(AVPlayerController *)controller;

// AVPlayer current play time was changed
- (void)AVPlayerControllerDidCurTimeChange:(AVPlayerController *)controller;

// Enter or exit full screen mode
- (void)AVPlayerControllerDidEnterFullscreenMode:(AVPlayerController *)controller;
- (void)AVPlayerControllerDidExitFullscreenMode:(AVPlayerController *)controller;

@end
