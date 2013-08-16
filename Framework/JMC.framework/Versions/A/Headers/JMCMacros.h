/**
   Copyright 2011 Atlassian Software

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**/

#import "JMC.h"

#define JMC_BUNDLE_NAME @"JMC.bundle"

#define JMC_BUNDLE(filename) [[JMC frameworkBundlePath] stringByAppendingPathComponent:filename]

#define CREATE_IMAGE(filename) [[[UIImage alloc] initWithContentsOfFile:JMC_BUNDLE(filename)] autorelease]


#define JMCLocalizedString(key, comment) \
    [[JMC frameworkBundle] localizedStringForKey:(key) value:@"" table:@"JMCLocalizable"]

# define JMCALog(format, ...) NSLog((@"%d %s " format), __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__);

# ifdef JMC_DEBUG
#  define JMCDLog(format, ...) JMCALog(format, ##__VA_ARGS__);
# else
#   define JMCDLog(...)
# endif


#define JMCPresentViewController(currentController, controller) \
 ([UIViewController instancesRespondToSelector:@selector(presentViewController:animated:completion:)] ? \
    [currentController presentViewController:controller animated:YES completion:nil] : \
    [currentController presentModalViewController:controller animated:YES])

#define JMCDismissViewController(currentController) \
([UIViewController instancesRespondToSelector:@selector(dismissViewControllerAnimated:completion:)] ? \
    [currentController dismissViewControllerAnimated:YES completion:nil] : \
    [currentController dismissModalViewControllerAnimated:YES])


