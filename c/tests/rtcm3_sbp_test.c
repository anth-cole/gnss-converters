/*
 * Copyright (C) 2017 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "rtcm3_sbp_test.h"
#include <rtcm3_sbp.h>
#include <stdio.h>
#include <stdlib.h>

void sbp_callback(u8 msg_id, u8 length, u8 *buffer){
  (void)msg_id;
  (void)length;
  (void)buffer;
}

void test_RTCM3_decode(void){


  struct rtcm3_sbp_state state;
  rtcm2sbp_init(&state, sbp_callback);

  FILE* fp = fopen("../../tests/data/20170222_gps_ephemeris_331200.rtcm3","rb");

  u8 buffer[2048];

  if(fp == NULL){
    fprintf(stderr, "Can't open input file!\n");
    exit(1);
  }

  fread(buffer, 2048, 1, fp);

  rtcm2sbp_decode_frame(buffer, 2048, &state);


  return;
}

int main(void) {
  test_RTCM3_decode();
}
