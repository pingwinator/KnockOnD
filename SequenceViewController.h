//
//  SequenceViewController.h
//  KnockOnD
//
//  Created by Oleksandr Tymoshenko on 09-09-11.
//  Copyright 2009 BluezBox. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SequenceViewControllerDelegate;

@interface NameCell : UITableViewCell
{
    UITextField *textField;
}

@property (nonatomic,retain) UITextField *textField;
- (void) dealloc;

@end

@interface PortCell : UITableViewCell
{
    UITextField *portField;
    UISegmentedControl *protoSegment;
}

@property (nonatomic,retain) UITextField *portField;
@property (nonatomic,retain) UISegmentedControl *protoSegment;

- (void) dealloc;

@end


@interface SequenceViewController : UIViewController<UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate> {
    IBOutlet UITableView *seqTableView;
    UITextField *activeTextField;
    NSMutableArray *ports;
    NSString *name;
    NSString *host;
    NSUInteger delay;
    id <SequenceViewControllerDelegate> delegate;
}

@property (nonatomic, assign) id <SequenceViewControllerDelegate> delegate;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *host;
@property (nonatomic, retain) NSMutableArray *ports;
@property (nonatomic, assign) NSUInteger delay;

- (IBAction) save: (id)sender;
- (IBAction) cancel: (id)sender;
- (void) keyboardWillShow: (id)sender;
- (void) keyboardWillHide: (id)sender;
- (void) protoChanged: (id)sender;
- (void) alert: (NSString*)msg;
@end

@protocol SequenceViewControllerDelegate
- (void)sequenceViewControllerDidFinish:(SequenceViewController *)controller accepted:(BOOL)accepted;
@end

