#include "MainComponent.h"
#include "MusicPlayer.hh"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(&audioPlayerButton);
    audioPlayerButton.setButtonText("Open Music Player");
    audioPlayerButton.onClick = [this]() { this->openMusicPlayer(); };

    addAndMakeVisible(&graphicWindowButton);
    graphicWindowButton.setButtonText("Open openGL Demo");
    graphicWindowButton.onClick = [this]() { this->openGraphicWindow(); };

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
    playerWindow.release();
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
    juce::AlertWindow::showAsync(juce::MessageBoxOptions()
        .withIconType(juce::MessageBoxIconType::InfoIcon)
        .withTitle("Permissions warning")
        .withMessage("External storage access permission not granted, some files"
            " may be inaccessible.")
        .withButton("OK")
        .withButton("More.."),
        juce::ModalCallbackFunction::create([](int index) {
            auto msg = std::string();

            if (index == 1) msg = "You pressed Ok";
            else msg = "You pressed More..";

            juce::AlertWindow::showAsync(juce::MessageBoxOptions()
                .withIconType(juce::MessageBoxIconType::InfoIcon)
                .withTitle("Result")
                .withMessage(msg),
                nullptr);
        })
    );

    playerWindow.reset(new akasha::PlayerWindow(akasha::musicPlayerName));
    playerWindow->setBounds(200, 200, 300, 300);
    playerWindow->setVisible(true);
}

auto MainComponent::openGraphicWindow() -> void {
    //graphicWindow.reset(new akasha::GraphicWindow())
}