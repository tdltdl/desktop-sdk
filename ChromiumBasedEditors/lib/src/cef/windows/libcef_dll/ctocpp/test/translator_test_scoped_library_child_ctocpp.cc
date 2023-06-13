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
// $hash=b591e72d8eb23b5ed62a7d877e5a498211fd029f$
//

#include "libcef_dll/ctocpp/test/translator_test_scoped_library_child_ctocpp.h"
#include "libcef_dll/ctocpp/test/translator_test_scoped_library_child_child_ctocpp.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefOwnPtr<CefTranslatorTestScopedLibraryChild>
CefTranslatorTestScopedLibraryChild::Create(int value, int other_value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_translator_test_scoped_library_child_t* _retval =
      cef_translator_test_scoped_library_child_create(value, other_value);

  // Return type: ownptr_same
  return CefTranslatorTestScopedLibraryChildCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
int CefTranslatorTestScopedLibraryChildCToCpp::GetOtherValue() {
  cef_translator_test_scoped_library_child_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_other_value))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_other_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefTranslatorTestScopedLibraryChildCToCpp::SetOtherValue(int value) {
  cef_translator_test_scoped_library_child_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_other_value))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_other_value(_struct, value);
}

NO_SANITIZE("cfi-icall")
int CefTranslatorTestScopedLibraryChildCToCpp::GetValue() {
  cef_translator_test_scoped_library_t* _struct =
      reinterpret_cast<cef_translator_test_scoped_library_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_value))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefTranslatorTestScopedLibraryChildCToCpp::SetValue(int value) {
  cef_translator_test_scoped_library_t* _struct =
      reinterpret_cast<cef_translator_test_scoped_library_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, set_value))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value(_struct, value);
}

// CONSTRUCTOR - Do not edit by hand.

CefTranslatorTestScopedLibraryChildCToCpp::
    CefTranslatorTestScopedLibraryChildCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefTranslatorTestScopedLibraryChildCToCpp::
    ~CefTranslatorTestScopedLibraryChildCToCpp() {}

template <>
cef_translator_test_scoped_library_child_t*
CefCToCppScoped<CefTranslatorTestScopedLibraryChildCToCpp,
                CefTranslatorTestScopedLibraryChild,
                cef_translator_test_scoped_library_child_t>::
    UnwrapDerivedOwn(CefWrapperType type,
                     CefOwnPtr<CefTranslatorTestScopedLibraryChild> c) {
  if (type == WT_TRANSLATOR_TEST_SCOPED_LIBRARY_CHILD_CHILD) {
    return reinterpret_cast<cef_translator_test_scoped_library_child_t*>(
        CefTranslatorTestScopedLibraryChildChildCToCpp::UnwrapOwn(
            CefOwnPtr<CefTranslatorTestScopedLibraryChildChild>(
                reinterpret_cast<CefTranslatorTestScopedLibraryChildChild*>(
                    c.release()))));
  }
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
cef_translator_test_scoped_library_child_t*
CefCToCppScoped<CefTranslatorTestScopedLibraryChildCToCpp,
                CefTranslatorTestScopedLibraryChild,
                cef_translator_test_scoped_library_child_t>::
    UnwrapDerivedRaw(CefWrapperType type,
                     CefRawPtr<CefTranslatorTestScopedLibraryChild> c) {
  if (type == WT_TRANSLATOR_TEST_SCOPED_LIBRARY_CHILD_CHILD) {
    return reinterpret_cast<cef_translator_test_scoped_library_child_t*>(
        CefTranslatorTestScopedLibraryChildChildCToCpp::UnwrapRaw(
            CefRawPtr<CefTranslatorTestScopedLibraryChildChild>(
                reinterpret_cast<CefTranslatorTestScopedLibraryChildChild*>(
                    c))));
  }
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType
    CefCToCppScoped<CefTranslatorTestScopedLibraryChildCToCpp,
                    CefTranslatorTestScopedLibraryChild,
                    cef_translator_test_scoped_library_child_t>::kWrapperType =
        WT_TRANSLATOR_TEST_SCOPED_LIBRARY_CHILD;
