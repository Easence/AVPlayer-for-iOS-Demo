//
//  MovieInfosViewController.m
//  AVPlayer
//
//  Created by apple on 13-5-29.
//  Copyright (c) 2013年 iMoreApp Inc. All rights reserved.
//

#import "MovieInfosViewController.h"

@implementation MovieInfosViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
	// Do any additional setup after loading the view.
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        
        @autoreleasepool {
            NSTimeInterval duration = 0;
            CGSize frameSize = CGSizeZero;
            UIImage *thumbnails = nil;
            
            MovieParser *mp = [[MovieParser alloc] init];
            if ([mp open:self.moviePath]) {
                
                duration = mp.duration;
                frameSize = CGSizeMake(mp.frameWidth, mp.frameHeight);
                
                [mp seek:fminf(20, mp.duration/2.0)];
                NSArray *rgbframes = [mp decodeFrames:5];
                
                if (rgbframes.count > 0) {
                    NSSet *set = [NSSet setWithArray:rgbframes];
                    AVVideoFrameRGB *rgbframe = [set anyObject];
                    thumbnails = [rgbframe asImage];
                }
                mp = nil;
            }
            
            dispatch_async(dispatch_get_main_queue(), ^{
                self.durationLabel.text = [AVPlayerController formatTimeInterval:duration isLeft:NO];
                self.videoSizeLabel.text = [NSString stringWithFormat:@"%d * %d", (int)frameSize.width, (int)frameSize.height];
                self.thumbnailsImageView.image = thumbnails;
            });
        }
    });
}


@end
