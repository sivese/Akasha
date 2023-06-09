/* 
    example repository

    => https://github.com/juce-framework/JUCE/tree/master/examples

*/
#include <JuceHeader.h>
#include "MainComponent.h"

class AkashaApplication  : public juce::JUCEApplication
{ 
public:
    AkashaApplication() {}

    const juce::String getApplicationName() override       { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override             { return true; }

    void initialise (const juce::String& commandLine) override
    {
        // This method is where you should put your application's initialisation code..

        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..

        mainWindow = nullptr; // (deletes our window)
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted (const juce::String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

#pragma region Window
    /*
        Inner class, window class
    */
    class MainWindow : public juce::DocumentWindow {
    public:
        MainWindow (juce::String name) : DocumentWindow (
            name,
            juce::Desktop::getInstance()
                .getDefaultLookAndFeel()
                .findColour (juce::ResizableWindow::backgroundColourId),
            DocumentWindow::allButtons
        ) {
            setUsingNativeTitleBar (false);
            setContentOwned (new MainComponent(), true);

           #if JUCE_IOS || JUCE_ANDROID
            setFullScreen (true);
           #else
            setResizable (true, true);
            centreWithSize (getWidth(), getHeight());
           #endif

            setVisible (true);
        }

        void closeButtonPressed() override {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };
#pragma endregion

private:
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION (AkashaApplication)
