/*
==============================================================================
This file was auto-generated!
It contains the basic framework code for a JUCE plugin processor.
==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Vibrato.h"
#include "ErrorDef.h"


//==============================================================================
/**
*/
class VibratoPluginAudioProcessor : public AudioProcessor
{
public:
	//==============================================================================
	VibratoPluginAudioProcessor();
	~VibratoPluginAudioProcessor();

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(AudioBuffer<float>&, MidiBuffer&) override;
	void processBlockBypassed(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;

<<<<<<< HEAD
	//==============================================================================
	AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const String getName() const override;
=======
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;
    void processBlockBypassed (AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;
    
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
>>>>>>> 9fce03c7ec7c3162f2b18bf58dcf51e835f3564e

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const String getProgramName(int index) override;
	void changeProgramName(int index, const String& newName) override;

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

	//==============================================================================
	void setParameter(int iParamIdx, float fNewValue) override;
	float getParameter(int iParamIdx) override;

	float fModFreq;
	float fModWidth;
	CVibrato *pCVibrato;

    //==============================================================================
    void setParameter (int iParamIdx, float fNewValue) override;
    float getParameter(int iParamIdx) override;
    
    float fModFreq;
    float fModWidth;
    
private:
<<<<<<< HEAD
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VibratoPluginAudioProcessor)

		

	const float fMaxModWidth = 0.1;
	bool bByPass;

};
=======
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VibratoPluginAudioProcessor)
    
    CVibrato *pCVibrato;
    
    const float fMaxModWidth = 0.1;
    bool bByPass;
    
};
>>>>>>> 9fce03c7ec7c3162f2b18bf58dcf51e835f3564e
