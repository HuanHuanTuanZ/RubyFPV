#pragma once
#include "menu_objects.h"
#include "../../base/models.h"
#include "menu_item_select.h"
#include "../popup.h"

#define MAX_MENU_CHANNELS 100

class MenuSearch: public Menu
{
   public:
      MenuSearch();
      virtual void valuesToUI();
      virtual void Render();
      virtual void onShow();
      virtual int onBack();
      virtual void onReturnFromChild(int returnValue);  
      virtual void onSelectItem();
      void setSpectatorOnly();

   private:
      void _populate_search_frequencies();

      int render_search_step;
      bool search_finished_with_no_results;
      int m_SearchBandIndex;
      bool m_bIsSearchPaused;
      bool m_SpectatorOnlyMode;
      bool m_bIsSearchingSiK;
      bool m_bIsSearchingManual;
      bool m_bIsSearchingAuto;
      bool m_bDidConnectToAVehicle;
      int m_nSkippedCount;
      int m_SearchChannelsCount;
      u32* m_pSearchChannels;
      bool m_bMustSwitchBack;
      u32 m_FrequencyOriginal[MAX_RADIO_INTERFACES];
      Model* m_pModelOriginal;
      u32 m_CurrentSearchFrequencyKhz;

      MenuItemSelect* m_pItemSelectBand;
      MenuItemSelect* m_pItemsSelectFreq;
      Popup* m_pPopupSearch;

      u32 m_Channels[MAX_MENU_CHANNELS];
      int m_NumChannels;
      u32 m_SupportedBands;
      u8 m_SupportedBandsList[8];
      int m_iCountSupportedBands;
      
      int m_IndexBand;
      int m_IndexStartSearch;
      int m_IndexManualSearch;

      bool m_bHasSiKRadio;
      MenuItemSelect* m_pItemsSelect[10];
      int m_IndexSiKInfo;
      int m_IndexSiKAirRate;
      int m_IndexSiKECC;
      int m_IndexSiKLBT;
      int m_IndexSiKMCSTR;

      void stopSearch();
      void startSearch();
      void onSearchStep();

      void createSearchPopup();
};