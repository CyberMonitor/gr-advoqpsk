/* -*- c++ -*- */
/* 
 * Copyright 2020 Zelin Yun.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ADVOQPSK_ADVOQPSK_SYNC_IMPL_H
#define INCLUDED_ADVOQPSK_ADVOQPSK_SYNC_IMPL_H

#include <advoqpsk/advoqpsk_sync.h>

namespace gr
{
  namespace advoqpsk
  {
    class advoqpsk_sync_impl : public advoqpsk_sync
    {
    private:
      int d_bufHeadLen;
      int d_bufMaxLen;
      gr_complexd *d_pBuf;
      double *d_pBufPower;
      double *d_pBufRad;
      double *d_pBufCc;
      double d_ccThreshold;
      double d_RadStepCompensation;

    public:
      advoqpsk_sync_impl(float ccThreshold);
      ~advoqpsk_sync_impl();

      int work(int noutput_items,
               gr_vector_const_void_star &input_items,
               gr_vector_void_star &output_items);
      double fFindA7CfoRadStep(gr_complexd *p_sigIn);
      double fCrossCorrelationA7(gr_complexd *p_sigIn, double p_sigPwrIn, double p_phaseDegStep);
      double fCrossCorrelationZz(gr_complexd *p_sigIn, double p_sigPwrIn, double p_phaseDegStep);
    };
  } // namespace advoqpsk
} // namespace gr

#endif /* INCLUDED_ADVOQPSK_ADVOQPSK_SYNC_IMPL_H */
