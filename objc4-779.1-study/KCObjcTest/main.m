//
//  main.m
//  studyobjc4
//
//  Created by apple on 2020/3/10.
//

#import <Foundation/Foundation.h>
#import "TestObj+Categor.h"
static TestObj *myObj = nil;
/*
 objc-alloc-step  oc对象alloc的过程
 objc-dealloc-step oc对象dealloc的过程
 objc-associateObject-step 关联对象过程
 objc-weakpointer-step weak引用过程
 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        NSThread *th = [[NSThread alloc] initWithBlock:^{
//            NSLog(@"===-=-=");
//        }];
//        [th start];
        
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3.f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            printf("调用[[TestObj alloc] init]\n");
            
            TestObj *obj = [[TestObj alloc] init];
            obj.catName = @"catName";
            NSLog(@"%@",obj.catName);
            __weak TestObj *weakObj = obj;
            NSLog(@"%@",weakObj);
        });
        
    
//        NSDate *stopDate = [[[NSDate alloc] init] dateByAddingTimeInterval:30.f];
//        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:stopDate];
        [[NSRunLoop currentRunLoop] run];
    }
    return 0;
}
