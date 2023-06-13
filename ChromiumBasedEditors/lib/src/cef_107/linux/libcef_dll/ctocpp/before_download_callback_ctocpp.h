// Copyright (c) 2022 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=f2b6a61b2459566fef19ee3824d7c155bf7f25d1$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_BEFORE_DOWNLOAD_CALLBACK_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_BEFORE_DOWNLOAD_CALLBACK_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_download_handler_capi.h"
#include "include/cef_download_handler.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefBeforeDownloadCallbackCToCpp
    : public CefCToCppRefCounted<CefBeforeDownloadCallbackCToCpp,
                                 CefBeforeDownloadCallback,
                                 cef_before_download_callback_t> {
 public:
  CefBeforeDownloadCallbackCToCpp();
  virtual ~CefBeforeDownloadCallbackCToCpp();

  // CefBeforeDownloadCallback methods.
  void Continue(const CefString& download_path, bool show_dialog) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_BEFORE_DOWNLOAD_CALLBACK_CTOCPP_H_
