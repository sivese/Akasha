/*
  ==============================================================================

    MusicPlayer.cpp
    Created: 8 Jun 2023 8:43:06pm
    Author:  Admin

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MusicPlayer.hh"

using namespace akasha;

//==============================================================================
MusicPlayer::MusicPlayer()
{

}


MusicPlayer::~MusicPlayer()
{
}

void MusicPlayer::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("MusicPlayer", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void MusicPlayer::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
