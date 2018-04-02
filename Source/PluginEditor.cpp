/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VibratoPluginAudioProcessorEditor::VibratoPluginAudioProcessorEditor (VibratoPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (300, 300);
	initializeSlider(m_sliderModFreq, 0.0f, 127.0f, 1.0f, 40, 30, 20, 165,"ModFreq", 50.0f);
	initializeSlider(m_sliderModWidth, 0.0f, 1.0f, 0.01f, 100, 30, 20, 165, "ModWidth", 0.5f);
	initializeButton(m_toggleButton, 150, 30, 80, 40);
}

VibratoPluginAudioProcessorEditor::~VibratoPluginAudioProcessorEditor()
{
}

//==============================================================================
void VibratoPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
	g.drawFittedText("ModFreq", 0, 0, getWidth()-200, 30, Justification::centred, 1);
	g.drawFittedText("ModWidth", 0, 0, getWidth() - 60, 30, Justification::centred, 1);
}

void VibratoPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void VibratoPluginAudioProcessorEditor::buttonClicked(Button* button)
{
}

void VibratoPluginAudioProcessorEditor::sliderValueChanged(Slider * slider)
{
}

void VibratoPluginAudioProcessorEditor::initializeSlider(Slider & slider, float Min, float Max, float Interval, float x, float y, float width, float height, const String & displayText, float fdefault)
{
	slider.setSliderStyle(Slider::LinearBarVertical);
	slider.setRange(Min, Max, Interval);
	slider.setTextValueSuffix(displayText);
	slider.setValue(fdefault);
	slider.setBounds(x,y,width,height);
	slider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	slider.addListener(this);
	addAndMakeVisible(&slider);
}

void VibratoPluginAudioProcessorEditor::initializeButton(ToggleButton &button, float x, float y, float width, float height)
{
	button.setBounds(x, y, width, height);
	button.addListener(this);
	button.setButtonText("By Pass");
	button.setToggleState(0, dontSendNotification);
	addAndMakeVisible(&button);

}
