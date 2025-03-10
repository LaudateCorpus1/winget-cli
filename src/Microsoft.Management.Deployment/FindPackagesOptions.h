// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "FindPackagesOptions.g.h"

namespace winrt::Microsoft::Management::Deployment::implementation
{
#if USE_PROD_CLSIDS 
    [uuid("572DED96-9C60-4526-8F92-EE7D91D38C1A")]
#else
    [uuid("1BD8FF3A-EC50-4F69-AEEE-DF4C9D3BAA96")]
#endif
    struct FindPackagesOptions : FindPackagesOptionsT<FindPackagesOptions>
    {
        FindPackagesOptions() = default;

        winrt::Windows::Foundation::Collections::IVector<winrt::Microsoft::Management::Deployment::PackageMatchFilter> Selectors();
        winrt::Windows::Foundation::Collections::IVector<winrt::Microsoft::Management::Deployment::PackageMatchFilter> Filters();
        uint32_t ResultLimit();
        void ResultLimit(uint32_t value);

#if !defined(INCLUDE_ONLY_INTERFACE_METHODS)
    private:
        uint32_t m_resultLimit = 0;
        Windows::Foundation::Collections::IVector<Microsoft::Management::Deployment::PackageMatchFilter> m_selectors{ 
            winrt::single_threaded_vector<winrt::Microsoft::Management::Deployment::PackageMatchFilter>() };
        Windows::Foundation::Collections::IVector<Microsoft::Management::Deployment::PackageMatchFilter> m_filters{ 
            winrt::single_threaded_vector<winrt::Microsoft::Management::Deployment::PackageMatchFilter>() };
#endif
    };
}

#if !defined(INCLUDE_ONLY_INTERFACE_METHODS)
namespace winrt::Microsoft::Management::Deployment::factory_implementation
{
    struct FindPackagesOptions : FindPackagesOptionsT<FindPackagesOptions, implementation::FindPackagesOptions>
    {
    };
}
#endif
