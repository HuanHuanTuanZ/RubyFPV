#pragma once

#define MAX_VIDEO_BITRATE_HISTORY_VALUES 30
// About 1.5 seconds of history at an update rate of 20 times/sec (50 ms)

typedef struct
{
   u32 uTimeStampTaken;
   u32 uTotalBitrateBPS;
   u32 uVideoBitrateBPS;
}
type_processor_tx_video_bitrate_sample;


class ProcessorTxVideo
{
   public:
      ProcessorTxVideo(int iVideoStreamIndex, int iCameraIndex);
      virtual ~ProcessorTxVideo();

      bool init();
      bool uninit();
      
      void periodicLoop();

      u32 getCurrentVideoBitrate();
      u32 getCurrentVideoBitrateAverage();
      u32 getCurrentVideoBitrateAverageLastMs(u32 uMilisec);
      u32 getCurrentTotalVideoBitrate();
      u32 getCurrentTotalVideoBitrateAverage();
      u32 getCurrentTotalVideoBitrateAverageLastMs(u32 uMilisec);
      
      void setLastRequestedAdaptiveVideoLevelFromController(int iLevel);
      void setLastSetCaptureVideoBitrate(u32 uBitrate, bool bInitialValue, int iSource);

      int getLastRequestedAdaptiveVideoLevelFromController();
      u32 getLastSetCaptureVideoBitrate();

      static int m_siInstancesCount;

   protected:
      bool m_bInitialized;
      int m_iInstanceIndex;
      int m_iVideoStreamIndex;
      int m_iCameraIndex;
      int m_iLastRequestedAdaptiveVideoLevelFromController;
      u32 m_uInitialSetCaptureVideoBitrate;
      u32 m_uLastSetCaptureVideoBitrate;

      u32 m_uIntervalMSComputeVideoBitrateSample;
      u32 m_uTimeLastVideoBitrateSampleTaken;

      type_processor_tx_video_bitrate_sample m_BitrateHistorySamples[MAX_VIDEO_BITRATE_HISTORY_VALUES];
      int m_iVideoBitrateSampleIndex;

      u32 m_uVideoBitrateAverageSum;
      u32 m_uTotalVideoBitrateAverageSum;
      u32 m_uVideoBitrateAverage;
      u32 m_uTotalVideoBitrateAverage;
};

bool process_data_tx_video_init();
bool process_data_tx_video_uninit();

bool process_data_tx_video_command(int iRadioInterface, u8* pPacketBuffer);
bool process_data_tx_video_loop();

u8* process_data_tx_video_get_current_buffer_to_read_pointer();
int process_data_tx_video_get_current_buffer_to_read_size();
bool process_data_tx_video_on_new_data(u8* pData, int iDataSize);

bool process_data_tx_is_on_iframe();
int process_data_tx_video_has_packets_ready_to_send();
int process_data_tx_video_send_packets_ready_to_send(int howMany);

void process_data_tx_video_signal_encoding_changed();
void process_data_tx_video_signal_model_changed();

void process_data_tx_video_pause_tx();
void process_data_tx_video_resume_tx();

void process_data_tx_video_reset_retransmissions_history_info();

