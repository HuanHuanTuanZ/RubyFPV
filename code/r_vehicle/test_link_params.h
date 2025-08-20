#pragma once
#include "../base/base.h"
#include "../base/models.h"

bool test_link_is_in_progress();
bool test_link_is_applying_radio_params();
void test_link_process_received_message(int iInterfaceIndex, u8* pPacketBuffer);
type_radio_links_parameters* test_link_get_temp_radio_params();
void test_link_loop();
