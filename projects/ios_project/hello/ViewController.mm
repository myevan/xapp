//
//  ViewController.m
//  hello
//
//  Created by Song Young-jin on 2015. 4. 11..
//  Copyright (c) 2015년 com.example. All rights reserved.
//

#import "ViewController.h"

#include <x_foundation/XInformation.h>

using namespace xf;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    const char* signature = XInformation::GetTitle();
    self.mainLabel.text = [NSString stringWithUTF8String:signature];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
