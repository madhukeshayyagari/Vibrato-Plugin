/*
==============================================================================
This file was auto-generated!
It contains the basic framework code for a JUCE plugin editor.
==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Vibrato.h"




//==============================================================================
/**
*/
class VibratoPluginAudioProcessorEditor : public AudioProcessorEditor,
	public Button::Listener,
	public Slider::Listener
{
public:
	VibratoPluginAudioProcessorEditor(VibratoPluginAudioProcessor&);
	~VibratoPluginAudioProcessorEditor();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void sliderValueChanged(Slider* slider) override;
	void initializeSlider(Slider &slider, float Min, float Max, float Interval, float x, float y, float width, float height, const String &displayText, float fdefault);
	void initializeButton(ToggleButton &button, float x, float y, float width, float height);






private:
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	VibratoPluginAudioProcessor & processor;

	Slider m_sliderModWidth;
	Slider m_sliderModFreq;
	ToggleButton m_toggleButton;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VibratoPluginAudioProcessorEditor)
};