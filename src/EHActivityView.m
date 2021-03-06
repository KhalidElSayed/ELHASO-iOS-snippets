#import "EHActivityView.h"

#import <QuartzCore/CALayer.h>


@implementation EHActivityView

/** Returns an autoreleased already spinning white large indicator view.
 */
+ (EHActivityView*)get_white_large
{
	EHActivityView *activity = [[EHActivityView alloc]
		initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
	[activity startAnimating];
	return [activity autorelease];
}

/** Returns an autoreleased already spinning white indicator view.
 */
+ (EHActivityView*)get_white
{
	EHActivityView *activity = [[EHActivityView alloc]
		initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
	[activity startAnimating];
	return [activity autorelease];
}

/** Returns an autoreleased already spinning gray indicator view.
 */
+ (EHActivityView*)get_gray
{
	EHActivityView *activity = [[EHActivityView alloc]
		initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
	[activity startAnimating];
	return [activity autorelease];
}

/** Makes the activity indicator have a rounded corner semitranslucent frame.
 * Pass the size of the frame that you want the activity indicator to have and
 * its corner radius. The frame will be made half black, and the view's content
 * mode will be set to UIViewContentModeCenter, so you can center or resize it
 * any way you want.
 */
- (void)set_translucent:(CGSize)size corner:(int)radius
{
	self.contentMode = UIViewContentModeCenter;
	CGRect rect = self.frame;
	rect.size = size;
	self.frame = rect;
	self.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.5];
	self.layer.cornerRadius = radius;
}

@end

// vim:tabstop=4 shiftwidth=4 syntax=objc
