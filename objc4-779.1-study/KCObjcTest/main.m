//
//  main.m
//  studyobjc4
//
//  Created by apple on 2020/3/10.
//

#import <Foundation/Foundation.h>
#import "TestObj+Categor.h"
static TestObj *myObj = nil;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3.f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            printf("调用[[TestObj alloc] init]\n");
            TestObj *obj = [[TestObj alloc] init];
            obj.catName = @"catName";
            __weak TestObj *weakObj = obj;
            NSLog(@"%@",weakObj);
        });
        
//        NSDate *stopDate = [[[NSDate alloc] init] dateByAddingTimeInterval:30.f];
//        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:stopDate];
        [[NSRunLoop currentRunLoop] run];
    }
    return 0;
}
