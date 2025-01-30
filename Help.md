
SALT-XXXX-10: Verify Vendor Data Handling
 * Description: This test suite verifies license checkout behavior with different vendor data configurations, ensuring correct license sharing and separation based on vendor data and dup group settings.
 * Acceptance Criteria:
   * Licenses are shared when identical vendor data is used.
   * Licenses are not shared when distinct vendor data is used.
   * dup group = NONE prevents sharing, even with identical vendor data.
 * Test Cases:
   * TC_10.1_License_Sharing_Identical_Vendor_Data: Verify license sharing with identical vendor data.
   * TC_10.2_Separate_Checkouts_Distinct_Vendor_Data: Verify separate checkouts with distinct vendor data.
   * TC_10.3_Dup_Group_None_Prevents_Sharing: Verify dup group = NONE prevents sharing.
SALT-XXXX-11: Verify Options File Functionality
 * Description: This test suite validates the saltd.opt options file, verifying include/exclude list functionality for license checkout control.
 * Acceptance Criteria:
   * Excluded licenses cannot be checked out.
   * Included licenses (if available) can be checked out.
 * Test Cases:
   * TC_11.1_Exclude_License: Verify excluding a license prevents checkout.
   * TC_11.2_Include_License: Verify including a license allows checkout.
SALT-XXXX-12: Verify Other FNP Functions Behavior
 * Description: This test suite verifies the behavior of FNP functions: lc_checkout (presence check), lc_get_config, lc_userlist, and lc_get_attr.
 * Acceptance Criteria:
   * lc_checkout as presence check doesn't consume a license.
   * lc_get_config returns correct license configuration.
   * lc_userlist returns correct user list.
   * lc_get_attr returns correct license pool information.
   * Function behavior is correct when credits are disabled.
 * Test Cases:
   * TC_12.1_lc_checkout_Presence_Check: Verify lc_checkout as a presence check.
   * TC_12.2_lc_get_config_Retrieval: Verify lc_get_config information retrieval.
   * TC_12.3_lc_userlist_Retrieval: Verify lc_userlist user list retrieval.
   * TC_12.4_lc_get_attr_Retrieval: Verify lc_get_attr license pool info retrieval.
   * TC_12.5_FNP_Functions_No_Credits: Verify FNP function behavior with no credits.

SALT-XXXX-13: Verify License Time Out
 * Description: This test verifies the server's behavior regarding license reclamation when a client's license lease expires due to inactivity (no heartbeats).
 * Acceptance Criteria:
   * Server reclaims licenses after the license timeout period.
   * Credit-based licenses may not time out due to their nature.
   * Timeout values below one minute are allowed but may have limited effect.
 * Test Cases:
   * TC_13.1_License_Timeout_Reclamation: Verify license reclamation after timeout.
   * TC_13.2_Credit_License_No_Timeout: Verify credit-based licenses do not time out.
SALT-XXXX-14: Verify Client Time Out
 * Description: This test verifies the server's handling of client disconnections and license releases when a client times out.
 * Acceptance Criteria:
   * Licenses are released when the client times out.
 * Test Cases:
   * TC_14.1_Client_Timeout_License_Release: Verify license release on client timeout.
SALT-XXXX-15: Verify Client Heartbeats
 * Description: This test verifies the client's heartbeat mechanism, ensuring licenses are maintained while the client is active and that license loss is detected upon disconnection.
 * Acceptance Criteria:
   * Clients maintain licenses while sending heartbeats.
   * Clients detect license loss when the connection is broken.
   * Clients attempt to reacquire licenses upon reconnection.
 * Test Cases:
   * TC_15.1_Client_Heartbeat_License_Maintenance: Verify license maintenance with heartbeats.
   * TC_15.2_License_Loss_Detection: Verify license loss detection on disconnection.
   * TC_15.3_License_Reacquisition_Reconnect: Verify license reacquisition upon reconnection.

SALT-XXXX-20: Verify Server Configuration and Reporting Test Suite
 * Description: This comprehensive test suite validates all aspects of server configuration and reporting, ensuring correct behavior for timer values, report masking, and report content for credit-based licenses.  It verifies the server's ability to read and apply configuration settings, handle various timer formats, enforce report masking, and generate accurate reports.
 * Acceptance Criteria:
   * Timer Values:
     * Server correctly reads and utilizes configured timer values ("offlineTimer," "connIdleTimer," "beatTimer," "reportTimer," "diskCacheTimer").
     * Timer values support different units (seconds, minutes, hours).
     * Timer values can be provided as comma-separated lists with suffixes for different credit server states (normal, offline, credits checked out, credits checked out offline).
     * Invalid timer values are handled gracefully (e.g., default values are used).
   * Report Masking:
     * Report mask is enforced, with only specified fields included in reports.
     * Mandatory fields (e.g., feature name) are always included in reports, regardless of the mask.
   * Report Content (Credit-Based Licenses):
     * Server reports for checked-out credit-based licenses contain all expected fields with accurate values: "feature," "version," "signature," "ckoData," "vendor," "user," "host," "display," "project," "IP address," "PID," "when," "nlic," "handle," "flags," and "duration."
 * Test Cases:
   * TC_20.1_Timer_Values_Single_Valid: Verify server uses valid, single configured timer values.
   * TC_20.2_Timer_Values_Multiple_Units: Verify timer values with different units (s, m, h) are handled correctly.
   * TC_20.3_Timer_Values_Comma_Separated: Verify parsing of comma-separated timer values.
   * TC_20.4_Timer_Values_State_Suffixes: Verify interpretation of state-specific timer suffixes.
   * TC_20.5_Timer_Values_Invalid_Handling: Verify graceful handling of invalid timer values (e.g., non-numeric).
   * TC_20.6_Report_Masking_Enforcement: Verify report mask enforcement, including exclusion of masked fields.
   * TC_20.7_Report_Mandatory_Fields: Verify mandatory fields are always included, even if masked.
   * TC_20.8_Report_Content_All_Fields: Verify all expected fields are present in credit license reports.
   * TC_20.9_Report_Field_Accuracy: Verify the accuracy of all field values in credit license reports.

SALT-XXXX-20: Comprehensive Server Configuration and Reporting Test Suite
 * Description: This comprehensive test suite validates all aspects of server configuration and reporting, ensuring correct behavior for timer values, report masking, and report content for credit-based licenses.  It verifies the server's ability to read and apply configuration settings, handle various timer formats, enforce report masking, and generate accurate reports.
 * Acceptance Criteria:
   * Timer Values:
     * Server correctly reads and utilizes configured timer values ("offlineTimer," "connIdleTimer," "beatTimer," "reportTimer," "diskCacheTimer").
     * Timer values support different units (seconds, minutes, hours).
     * Timer values can be provided as comma-separated lists with suffixes for different credit server states (normal, offline, credits checked out, credits checked out offline).
     * Invalid timer values are handled gracefully (e.g., default values are used).
   * Report Masking:
     * Report mask is enforced, with only specified fields included in reports.
     * Mandatory fields (e.g., feature name) are always included in reports, regardless of the mask.
   * Report Content (Credit-Based Licenses):
     * Server reports for checked-out credit-based licenses contain all expected fields with accurate values: "feature," "version," "signature," "ckoData," "vendor," "user," "host," "display," "project," "IP address," "PID," "when," "nlic," "handle," "flags," and "duration."
 * Test Cases:
   * TC_20.1_Timer_Values_Single_Valid: Verify server uses valid, single configured timer values.
   * TC_20.2_Timer_Values_Multiple_Units: Verify timer values with different units (s, m, h) are handled correctly.
   * TC_20.3_Timer_Values_Comma_Separated: Verify parsing of comma-separated timer values.
   * TC_20.4_Timer_Values_State_Suffixes: Verify interpretation of state-specific timer suffixes.
   * TC_20.5_Timer_Values_Invalid_Handling: Verify graceful handling of invalid timer values (e.g., non-numeric).
   * TC_20.6_Report_Masking_Enforcement: Verify report mask enforcement, including exclusion of masked fields.
   * TC_20.7_Report_Mandatory_Fields: Verify mandatory fields are always included, even if masked.
   * TC_20.8_Report_Content_All_Fields: Verify all expected fields are present in credit license reports.
   * TC_20.9_Report_Field_Accuracy: Verify the accuracy of all field values in credit license reports.


SALT-XXXX-23: Report Resending Logic
 * Description: This test suite verifies the server's report resending logic, ensuring that reports are eventually sent even if initial attempts fail due to temporary issues like the server being offline.  It also checks the behavior of the report timer and accumulated metered time during these situations.
 * Acceptance Criteria:
   * If sending a report fails (e.g., server offline), the report is resent later.
   * The report resend delay is appropriate (e.g., exponential backoff).
   * Going past a report threshold does not affect the report resend delay.
   * Accumulated metered time is not affected by server offline periods that prevent report sending.
   * Before a report is to be sent, the mock CLS/mock server timer for regularly sending reports should be different than the report resend timer to avoid conflicts and allow proper detection of report resending.
 * Test Cases:
   * TC_23.1_Report_Resend_Offline: Verify reports are resent after the server comes back online.
   * TC_23.2_Report_Resend_Delay: Verify the report resend delay is appropriate.
   * TC_23.3_Report_Threshold_Resend: Verify report thresholds don't affect resend delay.
   * TC_23.4_Metered_Time_Offline: Verify metered time is unaffected by offline periods during report resending.
   * TC_23.5_Report_Timer_Conflict: Verify report resend timer and regular report timer do not conflict.
SALT-XXXX-24: Server Heartbeat Mechanism
 * Description: This test suite validates the server's heartbeat mechanism, which periodically sends heartbeat messages to the CLS/mock server to maintain the connection and inform the CLS/mock server of the server's continued operation.
 * Acceptance Criteria:
   * The server periodically sends heartbeat messages to the CLS/mock server.
   * The heartbeat interval is configurable.
   * If a heartbeat cannot be sent (e.g., CLS/mock server is unavailable), the server retries sending heartbeats.
   * The server logs heartbeat failures and recoveries.
 * Test Cases:
   * TC_24.1_Heartbeat_Periodic_Send: Verify the server periodically sends heartbeats.
   * TC_24.2_Heartbeat_Interval: Verify the heartbeat interval is configurable.
   * TC_24.3_Heartbeat_Retry: Verify heartbeat retries when the CLS/mock server is unavailable.
   * TC_24.4_Heartbeat_Logging: Verify heartbeat failures and recoveries are logged.
SALT-XXXX-25: Server Termination and Session Handling
 * Description: This test suite covers server termination scenarios, including normal shutdown and abnormal termination, ensuring proper session handling and communication with the CLS/mock server.
 * Acceptance Criteria:
   * Normal Shutdown:
     * When a credit server shuts down normally, it sends a termination message to the CLS/mock server.
     * The server section in the information file is updated to reflect the shutdown.
     * There is no report generated upon normal server shutdown.
   * Abnormal Termination:
     * If the server terminates abnormally (e.g., crash), the information file is updated to indicate the abnormal termination.
     * Upon restart, the server detects the previous abnormal termination and handles it appropriately (e.g., logs a warning, attempts to recover).
 * Test Cases:
   * TC_25.1_Normal_Shutdown_Message: Verify a termination message is sent on normal shutdown.
   * TC_25.2_Normal_Shutdown_Info_File: Verify the information file is updated on normal shutdown.
   * TC_25.3_Normal_Shutdown_No_Report: Verify no report is generated on normal shutdown.
   * TC_25.4_Abnormal_Termination_Info_File: Verify the information file is updated on abnormal termination.
   * TC_25.5_Abnormal_Termination_Restart: Verify the server handles abnormal termination upon restart.


SALT-XXXX-26: Information File Handling
 * Description: This test suite verifies the server's handling of the information file, including its creation, updates, content, and behavior in different scenarios (normal operation, corruption, missing file, credit enabling/disabling, unsent reports, and open sessions).
 * Acceptance Criteria:
   * Normal Operation:
     * The server periodically saves the report and session ID to the information file.
     * The file includes server configuration information.
     * The file indicates whether credit licensing is enabled.
     * The file is read only at server startup time.
   * File Absence/Corruption:
     * If the information file is missing, the server creates a new one.
     * If the information file is corrupt, the server logs an error and treats it as if it were missing (creates a new one).
   * Credit Enabling/Disabling:
     * The information file accurately reflects whether credit licensing is enabled or disabled.
     * When credits are disabled, the server logs a message indicating this.
   * Unsent Reports:
     * If a report is in the information file (unsent), it is sent when the server restarts.
     * After the unsent report is sent, it is removed from the information file.
   * Open Sessions:
     * The information file can indicate an open session (e.g., due to an improper shutdown).
     * If an open session is detected, a termination message is sent to the CLS/mock server before starting a new session.
 * Test Cases:
   * TC_26.1_File_Normal_Operation: Verify normal information file creation, updates, and content.
   * TC_26.2_File_Missing_Handling: Verify handling of a missing information file.
   * TC_26.3_File_Corrupt_Handling: Verify handling of a corrupt information file.
   * TC_26.4_File_Credits_Disabled: Verify the file reflects credits being disabled and the log message is present.
   * TC_26.5_File_Credits_Enabled: Verify the file reflects credits being enabled.
   * TC_26.6_File_Unsent_Report: Verify handling of an unsent report in the information file.
   * TC_26.7_File_Open_Session: Verify handling of an open session in the information file.

SALT-XXXX-27: Credit Enabling and Disabling
 * Description: This test suite verifies the server's behavior when enabling and disabling credit-based licensing.  It ensures that credit checks are enforced correctly and that the server responds appropriately to CLS/mock server requests to change the credit licensing status.
 * Acceptance Criteria:
   * Disabling Credits:
     * Attempts to check out credit-based licenses fail when credits are disabled.
     * This includes checkouts due to client heartbeats.
     * Reports are still sent for any active (non-credit) checkouts.
     * Existing credit-based licenses that were checked out remain checked out.
   * Enabling Credits:
     * Credit-based licenses can be checked out when credits are enabled.
   * CLS/Mock Server Interaction:
     * The CLS/mock server can enable and disable credits via the responses to init, report, heartbeat, and terminate messages.
 * Test Cases:
   * TC_27.1_Disable_Credits_Checkout_Fails: Verify credit license checkout fails when credits are disabled.
   * TC_27.2_Disable_Credits_Heartbeat_Fails: Verify credit license checkout due to heartbeats fails when credits are disabled.
   * TC_27.3_Disable_Credits_Reports_Sent: Verify reports are still sent for non-credit checkouts when credits are disabled.
   * TC_27.4_Disable_Credits_Existing_Licenses: Verify existing credit licenses remain checked out when credits are disabled.
   * TC_27.5_Enable_Credits_Checkout_Succeeds: Verify credit license checkout succeeds when credits are enabled.
   * TC_27.6_CLS_Control_Credits: Verify the CLS/mock server can control credit enabling/disabling.
SALT-XXXX-28: SAM IAM Integration
 * Description: This test suite validates the integration of the credit server with SAM IAM for authentication and authorization.  It covers various scenarios, including normal operation, headless client behavior, invalid client information, SAM IAM unavailability, token expiration, and session termination.
 * Acceptance Criteria:
   * Authentication:
     * The credit server obtains authentication tokens from SAM IAM for requests.
     * For the mock server, there are ways to generate fake authentication tokens.
   * Headless Client:
     * The credit server runs as a headless client.
     * If the credit server is not a headless client, it disables credit licensing and continues to operate.
   * Error Handling:
     * If the headless client information is invalid, the server logs an error and disables credit licensing.
     * If SAM IAM is unreachable, the server logs an error and disables credit licensing.
     * When an authentication token expires, the server refreshes it via SAM IAM.
     * If the refresh token expires, the server disables credit licensing.
     * If the SAM IAM session is terminated, the server disables credit licensing.
 * Test Cases:
   * TC_28.1_SAM_IAM_Authentication: Verify the server obtains authentication tokens from SAM IAM.
   * TC_28.2_Mock_Token_Generation: Verify the mock server can generate fake tokens.
   * TC_28.3_Headless_Client_Mode: Verify the server runs as a headless client.
   * TC_28.4_Non_Headless_Behavior: Verify the server disables credits if not running as headless.
   * TC_28.5_Invalid_Client_Info: Verify the server handles invalid headless client information.
   * TC_28.6_SAM_IAM_Unreachable: Verify the server handles SAM IAM unavailability.
   * TC_28.7_Token_Expiration_Refresh: Verify token refresh on expiration.
   * TC_28.8_Refresh_Token_Expiration: Verify the server handles refresh token expiration.
   * TC_28.9_SAM_IAM_Session_Termination: Verify the server handles SAM IAM session termination.





