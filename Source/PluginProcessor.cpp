/*
==============================================================================
This file was auto-generated!
It contains the basic framework code for a JUCE plugin processor.
==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VibratoPluginAudioProcessor::VibratoPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	)
#endif
{
	pCVibrato = 0;
}

VibratoPluginAudioProcessor::~VibratoPluginAudioProcessor()
{
	CVibrato::destroyInstance(pCVibrato);
}

//==============================================================================
const String VibratoPluginAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

bool VibratoPluginAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool VibratoPluginAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool VibratoPluginAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
	return true;
#else
	return false;
#endif
}

double VibratoPluginAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int VibratoPluginAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
				// so this should be at least 1, even if you're not really implementing programs.
}

int VibratoPluginAudioProcessor::getCurrentProgram()
{
	return 0;
}

void VibratoPluginAudioProcessor::setCurrentProgram(int index)
{
}

const String VibratoPluginAudioProcessor::getProgramName(int index)
{
	return {};
}

void VibratoPluginAudioProcessor::changeProgramName(int index, const String& newName)
{
}

//==============================================================================
void VibratoPluginAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	// Use this method as the place to do any pre-playback
	// initialisation that you need..

    auto totalNumInputChannels = getTotalNumInputChannels();
	
    CVibrato::createInstance(pCVibrato);
	pCVibrato->initInstance(fMaxModWidth, sampleRate, totalNumInputChannels);
	setParameter(0, fModFreqInit);
	setParameter(1, fModWidthInit);

}

void VibratoPluginAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
	
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VibratoPluginAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
	ignoreUnused(layouts);
	return true;
#else
	// This is the place where you check if the layout is supported.
	// In this template code we only support mono or stereo.
	if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
		&& layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
		return false;

	// This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
	if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
		return false;
#endif

	return true;
#endif
}
#endif

void VibratoPluginAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();

	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	
	if (!buttonState) {
		pCVibrato->process((float**)buffer.getArrayOfReadPointers(), buffer.getArrayOfWritePointers(), buffer.getNumSamples());
	}
	else {
        processBlockBypassed(buffer, midiMessages);
	}
	
}

void VibratoPluginAudioProcessor::processBlockBypassed(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	for (int i = getTotalNumInputChannels(); i < getTotalNumOutputChannels(); ++i)
		buffer.clear(i, 0, buffer.getNumSamples());
	for (int channel = 0; channel < getTotalNumInputChannels(); ++channel)
	{
		buffer.getWritePointer(channel);

	}
}
//==============================================================================
bool VibratoPluginAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* VibratoPluginAudioProcessor::createEditor()
{
	return new VibratoPluginAudioProcessorEditor(*this);
}

//==============================================================================
void VibratoPluginAudioProcessor::getStateInformation(MemoryBlock& destData)
{
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.
}

void VibratoPluginAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.
}

void VibratoPluginAudioProcessor::setParameter(int iParamIdx, float fNewValue)
{
	if (iParamIdx == 0)
	{
		fModFreq = fNewValue;
		pCVibrato->setParam(CVibrato::VibratoParam_t::kParamModFreqInHz, fModFreq);

	}
	else if (iParamIdx == 1)
	{
		fModWidth = fNewValue;
		pCVibrato->setParam(CVibrato::VibratoParam_t::kParamModWidthInS, fModWidth);
	}
	else
	{
		std::cout << "invalid index!" << std::endl;
		
	}

}

float VibratoPluginAudioProcessor::getParameter(int iParamIdx)
{
	if (iParamIdx == 0)
	{
		return pCVibrato->getParam(CVibrato::VibratoParam_t::kParamModFreqInHz);
	}
	else if (iParamIdx == 1)
	{
		return pCVibrato->getParam(CVibrato::VibratoParam_t::kParamModWidthInS);
	}
	else
	{
		std::cout << "invalid index, returning Mod Freq!" << std::endl;
		return pCVibrato->getParam(CVibrato::VibratoParam_t::kParamModFreqInHz);
	}
}
//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new VibratoPluginAudioProcessor();
}
