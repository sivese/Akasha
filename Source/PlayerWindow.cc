/*
  ==============================================================================

    PlayerWindow.cpp
    Created: 9 Jun 2023 12:59:58am
    Author:  drive

  ==============================================================================
*/

#include "PlayerWindow.hh"
#include "MusicPlayer.hh"

using namespace akasha;

PlayerWindow::PlayerWindow(juce::String name) : DocumentWindow(
    name,
    juce::Desktop::getInstance()
        .getDefaultLookAndFeel()
        .findColour(juce::ResizableWindow::backgroundColourId),
    DocumentWindow::allButtons
) {
    setUsingNativeTitleBar(false);
    setContentOwned(new MusicPlayer(), true);

#if JUCE_IOS || JUCE_ANDROID
    setFullScreen(true);
#else
    setResizable(true, true);
    centreWithSize(getWidth(), getHeight());
#endif

    setVisible(true);
}

PlayerWindow::~PlayerWindow() { }

void PlayerWindow::closeButtonPressed() {
    delete this;
}