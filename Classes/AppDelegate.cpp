#include "AppDelegate.h"
#include "Common.h"
#include "MainScene.h"
#include "LevelSelectionScene.h"
#include <vector>
#include <array>

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate() {
    
}

AppDelegate::~AppDelegate()
{
}

// Information about resources
typedef struct tagResource
{
    cocos2d::Size size; // The size that this resource is designed for
    cocos2d::Size useIfScreenOverSize; // If teh screen size is more than this value, this resource is a valid choice
    char directory[100]; // The name of the directory containing resources of this type
} Resource;

// Define all our resource types and locations
static Resource largeResource  =  { Size(1440, 960), Size(1200, 800), "UHD"};
static Resource mediumResource =  { Size(960, 640), Size(720, 480),  "HD" };
static Resource smallResource  =  { Size(480, 320), Size(0, 0),   "SD" };

// Declare an array containing the resource descriptions, from largest to smallest
static std::array<Resource, 3> resources{{largeResource, mediumResource, smallResource}};

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("NumberPuzzle", Rect(0, 0, 1920, 1080));
        director->setOpenGLView(glview);
    }
    
    director->getOpenGLView()->setDesignResolutionSize(Constant::designResolutionSize.width, Constant::designResolutionSize.height, ResolutionPolicy::EXACT_FIT);
    
    // The vector we will use to build a list of paths to search for resources
    std::list<std::string> searchPaths;
    
    // Get the actual screen size
    static Size frameSize = glview->getFrameSize();
    
    CCLOG("FrameSize is (%.0f, %.0f)", frameSize.width,frameSize.height);
    
    // Define a silly scale factor so we know when we have calculated it
    float scaleFactor = -1;
    
    // Look through our resource definitions
    for (auto resource : resources)
    {
        // If the screen is wider or higher than the resolution of the resource...
        if (frameSize.width > resource.useIfScreenOverSize.width)//|| frameSize.width > resource.useIfScreenOverSize.width)
        {
            // Add this directory to the search path
            searchPaths.push_back(resource.directory);
            CCLOG("searching in %s", resource.directory);
            // If we haven't already determined the scale factor, calculated it based on this resources resolution. This would equal to
            // 2.0 for 1920, 1.0 for 960, 0.5 for 480
            if (scaleFactor == -1)
                scaleFactor = resource.size.width / Constant::designResolutionSize.width;
            
            float heightScale = frameSize.height / Constant::designResolutionSize.height / scaleFactor;
            float widthScale = frameSize.width / Constant::designResolutionSize.width / scaleFactor;
            Constant::frameRatioSize = Size(heightScale / widthScale, 1);
            Size ratio = Constant::frameRatioSize;
            
            // We scale x direction only.
			Constant::X_ALIGN *= ratio.width / ratio.height;
			Constant::Y_ALIGN *= 1;
            
            break;
        }
    }
    
    director->setContentScaleFactor(scaleFactor);
    FileUtils::getInstance()->addSearchPath(searchPaths.front());
    FileUtils::getInstance()->addSearchPath("res");
    FileUtils::getInstance()->addSearchPath("fonts");
    FileUtils::getInstance()->addSearchPath("effects");

    // Let's preload the sounds first
    MusicManager::getInstance().preload();

    // turn on display FPS
    director->setDisplayStats(false);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
//    auto scene = MainScene::createScene(0);
    auto scene = LevelSelectionScene::createScene(0);
    
    MusicManager::getInstance().playBackgroundMusic();
    
    // run
    director->runWithScene(scene);
    
    // Start Flurry Analytics Session
    AnalyticsManager::getInstance().init();
    AnalyticsManager::getInstance().startSession();
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    
    // if you use SimpleAudioEngine, it must be pause
    MusicManager::getInstance().pauseBackgroundMusic();

    // This should be called. However, it will only have effect on Android.
    AnalyticsManager::getInstance().endSession();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    
    // if you use SimpleAudioEngine, it must resume here
    MusicManager::getInstance().resumeBackgroundMusic();

    // Only do this on Android.
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    	AnalyticsManager::getInstance().startSession();
	#endif
}
