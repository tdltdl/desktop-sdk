// Copyright (c) 2022 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=8254165498a527d40517c1bc8ec413ad7a0ed259$
//

#ifndef CEF_INCLUDE_CAPI_CEF_MENU_MODEL_DELEGATE_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_MENU_MODEL_DELEGATE_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_menu_model_t;

///
/// Implement this structure to handle menu model events. The functions of this
/// structure will be called on the browser process UI thread unless otherwise
/// indicated.
///
typedef struct _cef_menu_model_delegate_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Perform the action associated with the specified |command_id| and optional
  /// |event_flags|.
  ///
  void(CEF_CALLBACK* execute_command)(struct _cef_menu_model_delegate_t* self,
                                      struct _cef_menu_model_t* menu_model,
                                      int command_id,
                                      cef_event_flags_t event_flags);

  ///
  /// Called when the user moves the mouse outside the menu and over the owning
  /// window.
  ///
  void(CEF_CALLBACK* mouse_outside_menu)(
      struct _cef_menu_model_delegate_t* self,
      struct _cef_menu_model_t* menu_model,
      const cef_point_t* screen_point);

  ///
  /// Called on unhandled open submenu keyboard commands. |is_rtl| will be true
  /// (1) if the menu is displaying a right-to-left language.
  ///
  void(CEF_CALLBACK* unhandled_open_submenu)(
      struct _cef_menu_model_delegate_t* self,
      struct _cef_menu_model_t* menu_model,
      int is_rtl);

  ///
  /// Called on unhandled close submenu keyboard commands. |is_rtl| will be true
  /// (1) if the menu is displaying a right-to-left language.
  ///
  void(CEF_CALLBACK* unhandled_close_submenu)(
      struct _cef_menu_model_delegate_t* self,
      struct _cef_menu_model_t* menu_model,
      int is_rtl);

  ///
  /// The menu is about to show.
  ///
  void(CEF_CALLBACK* menu_will_show)(struct _cef_menu_model_delegate_t* self,
                                     struct _cef_menu_model_t* menu_model);

  ///
  /// The menu has closed.
  ///
  void(CEF_CALLBACK* menu_closed)(struct _cef_menu_model_delegate_t* self,
                                  struct _cef_menu_model_t* menu_model);

  ///
  /// Optionally modify a menu item label. Return true (1) if |label| was
  /// modified.
  ///
  int(CEF_CALLBACK* format_label)(struct _cef_menu_model_delegate_t* self,
                                  struct _cef_menu_model_t* menu_model,
                                  cef_string_t* label);
} cef_menu_model_delegate_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_MENU_MODEL_DELEGATE_CAPI_H_
