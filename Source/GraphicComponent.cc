/*
  ==============================================================================

    GraphicComponent.cpp
    Created: 9 Jun 2023 6:40:36pm
    Author:  drive

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GraphicComponent.hh"

//==============================================================================
GraphicComponent::GraphicComponent()
{
    setOpaque(true);
    setSize(800, 600);
    setWantsKeyboardFocus(true);
    //startTimerHz(60);
}

GraphicComponent::~GraphicComponent()
{
}

void newOpenGLContextCreated()
{

}

void GraphicComponent::paint (juce::Graphics& g)
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
    g.drawText ("GraphicComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void GraphicComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
