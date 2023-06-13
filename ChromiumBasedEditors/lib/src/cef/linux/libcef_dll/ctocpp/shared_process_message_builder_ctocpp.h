// Copyright (c) 2023 The Chromium Embedded Framework Authors. All rights
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
// $hash=de0791f744ddb7e9e9256bb120f233cb64826188$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_SHARED_PROCESS_MESSAGE_BUILDER_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_SHARED_PROCESS_MESSAGE_BUILDER_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_shared_process_message_builder_capi.h"
#include "include/cef_shared_process_message_builder.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefSharedProcessMessageBuilderCToCpp
    : public CefCToCppRefCounted<CefSharedProcessMessageBuilderCToCpp,
                                 CefSharedProcessMessageBuilder,
                                 cef_shared_process_message_builder_t> {
 public:
  CefSharedProcessMessageBuilderCToCpp();
  virtual ~CefSharedProcessMessageBuilderCToCpp();

  // CefSharedProcessMessageBuilder methods.
  bool IsValid() override;
  size_t Size() override;
  void* Memory() override;
  CefRefPtr<CefProcessMessage> Build() override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_SHARED_PROCESS_MESSAGE_BUILDER_CTOCPP_H_
