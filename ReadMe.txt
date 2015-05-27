AppInsights SDK C++ (Alpha 1.0) - STATIC LIB

Introduction
This document describes how to integrate AppInsights into your projects and the APIs available to you.

Requirements:
This SDK will run on Windows C++ projects

Download
1. Download the zip file.
2. Unzip the folder to a location in your project path.  The folder contains a static lib and TelemetryClient.h file

Setup
1.  Drag the static lib into your project references folder
2.  Include Telemetry.h file in your project file where you wish to collect data

APIs
	// Get the singleton instance of the TelemetryClient
	static TelemetryClient *GetInstance(std::wstring iKey);

	// Free the singleton instance of the TelemetryClient
	void FreeInstance(const std::wstring& iKey);

	//
	// Event Tracking
	//
	void TrackEvent(const std::wstring& eventName);
	void TrackEvent(const std::wstring& eventName, const wstring_wstring_map& properties);
	void TrackEvent(const std::wstring& eventName, const wstring_wstring_map& properties, const std::map<std::wstring, double>& measurements);


	//
	// Trace Messages
	void TrackTrace(const std::wstring& message);
	void TrackTrace(const std::wstring& message, const wstring_wstring_map& properties);

	//
	// Track Metric
	//
	void TrackMetric(const std::wstring& name,const double& value);

	//
	// Track Page View
	void TrackPageView(const std::wstring& pageName);
	void TrackPageView(const std::wstring& pageName, const wstring_wstring_map& properties);
	void TrackPageView(const std::wstring& pageName, const wstring_wstring_map& properties, const std::map<std::wstring, double>& measurements);

	// Sends telemetry to the queue for transmission to Application Insights.
	void Track(Domain* telemetry);

	// Sends what is left in the queue to Application Insights.
	void Flush();

