/*
  ==============================================================================

    GraphicComponent.h
    Created: 9 Jun 2023 6:40:36pm
    Author:  drive

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class GraphicComponent  : public juce::Component, public juce::OpenGLRenderer
{
public:
    GraphicComponent();
    ~GraphicComponent() override;

    void newOpenGLContextCreated() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
private:
    juce::String vertexShader;
    juce::String fragmentShader;

    std::unique_ptr<juce::OpenGLShaderProgram> shader;
    std::unique_ptr<Shape> shape;
    std::unique_ptr<Attributes> attributes;
    std::unique_ptr<Uniforms> uniforms;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GraphicComponent)
};
