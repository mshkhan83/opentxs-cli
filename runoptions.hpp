/* See other files here for the LICENCE that applies here. */
/*
Template for new files, replace word "template" and later delete this line here.
*/

#ifndef INCLUDE_OT_NEWCLI_template
#define INCLUDE_OT_NEWCLI_template

#include "lib_common1.hpp"

namespace nOT {

INJECT_OT_COMMON_USING_NAMESPACE_COMMON_1; // <=== namespaces

/** Global options to run this program main() Eg used for developer's special options like +setdemo +setdebug.
This is NOT for all the other options that are parsed and executed by program. */
class cRunOptions {
	public:
		enum tRunMode { ///< Type of run mode - is this normal, or demonstration etc.
			eRunModeCurrent=1, ///< currently developed version
			eRunModeDemo, ///< best currently available Demo of something nice
			eRunModeNormal, ///< do the normal things that the program should do 
		};

	public: // TODO private and set/get later
		tRunMode mRunMode; ///< selected run mode

		bool mDebug; // turn debug on, Eg: +debug without it probably nothing will be written to debug (maybe just error etc)
		bool mDebugSendToFile; // send to file, Eg: for +debugfile
		bool mDebugSendToCerr; // send to cerr, Eg: for +debugcerr
		// if debug is set but not any other DebugSend* then we will default to sending to debugcerr

	public:
		cRunOptions();

		vector<string> ExecuteRunoptionsAndRemoveThem(const vector<string> & args);
		void Exec(string runoption); // eg: Exec("+debug");

		void Normalize();
};

extern cRunOptions gRunOptions;


}; // namespace nOT



#endif

