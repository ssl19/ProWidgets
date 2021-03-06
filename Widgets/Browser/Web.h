//
//  ProWidgets
//
//  1.0.0
//
//  Created by Alan Yip on 18 Jan 2014
//  Copyright 2014 Alan Yip. All rights reserved.
//

#import "header.h"

@interface PWURL : NSURL
@end

@interface PWWidgetBrowserWebView : UIView {
	
	BOOL _buttonHidden;
	
	UITextField *_textField;
	UIButton *_actionButton;
	UIView *_separator;
	UIWebView *_webView;
	UITableView *_suggestionView;
	//UILabel *_messageLabel;
}

@property(nonatomic, readonly) UITextField *textField;
@property(nonatomic, readonly) UIWebView *webView;
@property(nonatomic, readonly) UITableView *suggestionView;

- (void)setDelegate:(id<UITextFieldDelegate, UIWebViewDelegate, UITableViewDelegate, UITableViewDataSource>)delegate;

- (void)setTextFieldActive:(BOOL)active;
- (void)setButtonState:(BOOL)loading;
- (void)setButtonHidden:(BOOL)hidden;
//- (void)setMessageLabelText:(NSString *)text;
- (void)setWebViewActive:(BOOL)active;
- (void)updateSuggestionView:(BOOL)hidden;

@end

@interface PWWidgetBrowserWebViewController : PWContentViewController<UIActionSheetDelegate, UITextFieldDelegate, UIWebViewDelegate, UITableViewDelegate, UITableViewDataSource> {
	
	// preference value
	BOOL _hideHTTP;
	
	BOOL _loading;
	NSString *_lastTitle;
	NSString *_lastURLString;
	UIActionSheet *_actionSheet;
	
	UIBarButtonItem *_previous;
	UIBarButtonItem *_next;
	UIBarButtonItem *_more;
	
	PWWebRequest *_currentSuggestionRequest;
	NSArray *_suggestionData;
}

- (PWWidgetBrowserWebView *)webView;
- (void)loadURLString:(NSString *)urlString;
- (void)updateTitle;
- (void)updateNavigationButtonState;
- (void)setLoading:(BOOL)loading;

@end