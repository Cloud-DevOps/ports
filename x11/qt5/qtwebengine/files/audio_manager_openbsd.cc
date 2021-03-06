// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/audio/openbsd/audio_manager_openbsd.h"

#include "media/audio/audio_output_dispatcher.h"
#include "media/audio/sndio/sndio_input.h"
#include "media/audio/sndio/sndio_output.h"
#include "media/base/limits.h"
#include "media/base/media_switches.h"

namespace media {

// Maximum number of output streams that can be open simultaneously.
static const int kMaxOutputStreams = 4;

// Default sample rate for input and output streams.
static const int kDefaultSampleRate = 48000;

void AddDefaultDevice(AudioDeviceNames* device_names) {
  DCHECK(device_names->empty());
  device_names->push_front(AudioDeviceName(AudioManager::GetDefaultDeviceName(),
                                           AudioManagerBase::kDefaultDeviceId));
}

bool AudioManagerOpenBSD::HasAudioOutputDevices() {
  return true;
}

bool AudioManagerOpenBSD::HasAudioInputDevices() {
  return true;
}

void AudioManagerOpenBSD::ShowAudioInputSettings() {
  NOTIMPLEMENTED();
}

void AudioManagerOpenBSD::GetAudioInputDeviceNames(
    AudioDeviceNames* device_names) {
  DCHECK(device_names->empty());
  AddDefaultDevice(device_names);
}

void AudioManagerOpenBSD::GetAudioOutputDeviceNames(
    AudioDeviceNames* device_names) {
  AddDefaultDevice(device_names);
}

AudioParameters AudioManagerOpenBSD::GetInputStreamParameters(
    const std::string& device_id) {
  static const int kDefaultInputBufferSize = 1024;

  int user_buffer_size = GetUserBufferSize();
  int buffer_size = user_buffer_size ?
      user_buffer_size : kDefaultInputBufferSize;

  return AudioParameters(
      AudioParameters::AUDIO_PCM_LOW_LATENCY, CHANNEL_LAYOUT_STEREO,
      kDefaultSampleRate, 16, buffer_size);
}

AudioManagerOpenBSD::AudioManagerOpenBSD(AudioLogFactory* audio_log_factory)
    : AudioManagerBase(audio_log_factory) {
  DLOG(WARNING) << "AudioManagerOpenBSD";
  SetMaxOutputStreamsAllowed(kMaxOutputStreams);
}

AudioManagerOpenBSD::~AudioManagerOpenBSD() {
  Shutdown();
}

AudioOutputStream* AudioManagerOpenBSD::MakeLinearOutputStream(
    const AudioParameters& params) {
  DCHECK_EQ(AudioParameters::AUDIO_PCM_LINEAR, params.format());
  return MakeOutputStream(params);
}

AudioOutputStream* AudioManagerOpenBSD::MakeLowLatencyOutputStream(
    const AudioParameters& params,
    const std::string& device_id) {
  DLOG_IF(ERROR, !device_id.empty()) << "Not implemented!";
  DCHECK_EQ(AudioParameters::AUDIO_PCM_LOW_LATENCY, params.format());
  return MakeOutputStream(params);
}

AudioInputStream* AudioManagerOpenBSD::MakeLinearInputStream(
    const AudioParameters& params, const std::string& device_id) {
  DCHECK_EQ(AudioParameters::AUDIO_PCM_LINEAR, params.format());
  return MakeInputStream(params);
}

AudioInputStream* AudioManagerOpenBSD::MakeLowLatencyInputStream(
    const AudioParameters& params, const std::string& device_id) {
  DCHECK_EQ(AudioParameters::AUDIO_PCM_LOW_LATENCY, params.format());
  return MakeInputStream(params);
}

AudioParameters AudioManagerOpenBSD::GetPreferredOutputStreamParameters(
    const std::string& output_device_id,
    const AudioParameters& input_params) {
  // TODO(tommi): Support |output_device_id|.
  DLOG_IF(ERROR, !output_device_id.empty()) << "Not implemented!";
  static const int kDefaultOutputBufferSize = 2048;

  ChannelLayout channel_layout = CHANNEL_LAYOUT_STEREO;
  int sample_rate = kDefaultSampleRate;
  int buffer_size = kDefaultOutputBufferSize;
  int bits_per_sample = 16;
  if (input_params.IsValid()) {
    sample_rate = input_params.sample_rate();
    bits_per_sample = input_params.bits_per_sample();
    channel_layout = input_params.channel_layout();
    buffer_size = std::min(buffer_size, input_params.frames_per_buffer());
  }

  int user_buffer_size = GetUserBufferSize();
  if (user_buffer_size)
    buffer_size = user_buffer_size;

  return AudioParameters(
      AudioParameters::AUDIO_PCM_LOW_LATENCY, channel_layout,
      sample_rate, bits_per_sample, buffer_size);
}

AudioInputStream* AudioManagerOpenBSD::MakeInputStream(
    const AudioParameters& params) {
  DLOG(WARNING) << "MakeInputStream";
  return new SndioAudioInputStream(this,
             AudioManagerBase::kDefaultDeviceId, params);
}

AudioOutputStream* AudioManagerOpenBSD::MakeOutputStream(
    const AudioParameters& params) {
  DLOG(WARNING) << "MakeOutputStream";
  return new SndioAudioOutputStream(params, this);
}

// TODO(xians): Merge AudioManagerOpenBSD with AudioManagerPulse;
// static
AudioManager* CreateAudioManager(AudioLogFactory* audio_log_factory) {
  DLOG(WARNING) << "CreateAudioManager";
  return new AudioManagerOpenBSD(audio_log_factory);
}

}  // namespace media
