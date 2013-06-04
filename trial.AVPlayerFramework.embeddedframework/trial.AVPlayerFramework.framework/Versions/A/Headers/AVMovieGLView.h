//
//  AVMovieGLView.h
//  AVPlayer
//

#import <UIKit/UIKit.h>

@protocol AVMovieGLViewProtocol;

@interface AVMovieGLView : UIView <AVMovieGLViewProtocol>

- (id)initWithFrame:(CGRect)frame;

@end
