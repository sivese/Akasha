#include "MainComponent.h"
#include "MusicPlayer.hh"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(&audioPlayerButton);
    audioPlayerButton.setButtonText("Open Music Player");
    audioPlayerButton.onClick = [this]() { this->openMusicPlayer(); };

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized() {
    audioPlayerButton.setBounds(10, 10, getWidth() - 20, 20);
}

auto MainComponent::openMusicPlayer() -> void {
    playerWindow.reset(new akasha::PlayerWindow(akasha::musicPlayerName));
}