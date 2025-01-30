Parent Story: SALT-XXXX: Comprehensive Testing of Proxy/Credit Server Lifecycle
(Description: This story encompasses all testing related to the proxy/credit server's lifecycle, including initialization, startup, license management, shutdown, and various operational options.)
Child Stories:
1. SALT-XXXX-1: Verify Proxy/Credit Server Startup
 * Description: Tests server startup in regular and credit modes, verifying license handling and error logging.  Ensures the server starts correctly with various license configurations.
 * Acceptance Criteria:
   * Regular mode startup with regular license.
   * Credit mode startup with credit license.
   * Correct handling of multiple credit server IDs.
   * Proper error logging during startup.
 * Test Cases:
   * TC_Startup_Regular: Verify the server starts successfully in regular mode when a valid regular license is present in the configuration.
   * TC_Startup_Credit: Verify the server starts successfully in credit mode when a valid credit license is present in the configuration.
   * TC_Startup_MultipleIDs: Verify the server correctly handles situations where multiple credit server ID features are present in the license configuration (define the expected behavior when multiple IDs are present).
   * TC_Startup_Errors: Verify the server logs appropriate errors and handles invalid license configurations or other startup-related issues gracefully, preventing the server from starting if necessary.
 * Story Points: 5
2. SALT-XXXX-2: Verify Proxy/Credit Server License File Reread
 * Description: Tests dynamic license file reread, including mode switching and ECA handling.  Verifies the server can adapt to license changes without a restart.
 * Acceptance Criteria:
   * Seamless mode switching via reread.
   * Correct handling of same/different ECAs.
   * No disruption of existing licenses.
 * Test Cases:
   * TC_Reread_NormalToNormal: Verify that rereading the license file when the server is already in normal mode (and the file content is unchanged) does not cause any disruption or errors.
   * TC_Reread_ModeSwitch: Verify the server correctly switches modes (from normal to credit, and vice versa) when the license file is modified and reread.
   * TC_Reread_ECA: Verify the server correctly handles situations where the Entity/Customer Account (ECA) in the license file changes during a reread, including initiating a new CLS session if necessary.
 * Story Points: 5
3. SALT-XXXX-3: Verify Proxy/Credit Server Shutdown Procedures
 * Description: Tests controlled shutdown in various scenarios, including license handling and CLS reporting.  Verifies a clean and orderly shutdown process.
 * Acceptance Criteria:
   * Graceful shutdown with check-in and report.
   * Forced shutdown with check-in (if possible).
   * Correct behavior when Imgrd or saltd is killed.
 * Test Cases:
   * TC_Shutdown_Graceful: Verify the server shuts down gracefully when the Imdown command is used, including checking in all checked-out licenses and sending a report to the CLS.
   * TC_Shutdown_Forced: Verify the server attempts to check in all checked-out licenses and send a report to the CLS during a forced shutdown (e.g., using sc stop), even if the shutdown is not as graceful.
   * TC_Shutdown_Killed: Verify the server's behavior when the Imgrd or saltd process is unexpectedly terminated (e.g., killed), ensuring licenses are recovered and the server restarts or shuts down safely.
 * Story Points: 5
4. SALT-XXXX-4: Verify Proxy/Credit Server Initialization
 * Description: Tests initial communication and session establishment with the CLS/mock server. Verifies the server can correctly initialize and establish a connection.
 * Acceptance Criteria:
   * Successful session allows license checkout.
   * Disabled credits prevent checkout.
   * CLS offline triggers retries; errors disable credit usage.
 * Test Cases:
   * TC_Init_Success: Verify the server successfully establishes a session with the CLS when it is online and makes licenses available for checkout.
   * TC_Init_CreditsDisabled: Verify the server correctly handles initialization when credit-based licenses are disabled, preventing their checkout.
   * TC_Init_Offline: Verify the server's retry mechanism when the CLS is offline during initialization.
   * TC_Init_Error: Verify the server's error handling when initialization fails due to an error (e.g., invalid configuration).
 * Story Points: 5
5. SALT-XXXX-5: Verify Proxy/Credit Server Re-initialization Attempts
 * Description: Tests re-initialization attempts after initial failures. Verifies the server can recover from connectivity issues.
 * Acceptance Criteria:
   * Retries after offline.
   * Forced resend functionality.
   * Mock server testing.
 * Test Cases:
   * TC_Reinit_Offline: Verify the server automatically retries initialization after a timeout period if the initial attempt fails due to the CLS being offline.
   * TC_Reinit_Forced: Verify the server can be manually triggered to re-initialize (e.g., via an API call or command) to recover from transient connectivity issues.
   * TC_Reinit_MockServer: Verify the re-initialization behavior using a mock CLS server that can simulate going offline and coming back online.
 * Story Points: 3
6. SALT-XXXX-6: Verify Proxy/Credit Server License Checkout Options
 * Description: Tests license checkout options (linger, queuing, borrow, filter, sharing). Verifies the correct application of these options.
 * Acceptance Criteria:
   * Correct linger behavior for regular licenses.
   * No linger/queuing for credit licenses.
   * Credit borrow fails.
   * Checkout filter functionality.
   * Dup groups ignored for credit.
 * Test Cases:
   * TC_Options_Linger: Verify the server correctly applies linger behavior to regular licenses (holding them for a short period after check-in).
   * TC_Options_Queuing: Verify that queuing requests for credit-based licenses are ignored (as they should never be busy).
   * TC_Options_Borrow: Verify that attempts to "borrow" credit-based licenses (if such a concept exists in your system) fail as they should not be borrowable.
   * TC_Options_Filter: Verify that the license checkout filter function is correctly called and can be used to filter out specific licenses (e.g., credit-based licenses).
   * TC_Options_Sharing: Verify that the server ignores attempts to set dup groups (UHD) for credit-based licenses. All credit-based licenses should be treated as not shared (dup group NONE).
 * Story Points: 5
7. SALT-XXXX-7: Verify Proxy/Credit Server License Checkout/Check-in
 * Description: Tests core checkout/check-in (regular, credit, mixed). Verifies proper license management.
 * Acceptance Criteria:
   * Successful regular/credit checkout.
   * Mixed checkout handling.
   * Various check-in triggers.
   * License upgrade handling.
 * Test Cases:
   * TC_Checkout_Regular: Verify clients can successfully check out regular licenses when available.
   * TC_Checkout_Credit: Verify clients can successfully check out credit-based licenses when available.
   * TC_Checkout_Mixed: Verify the server correctly handles mixed checkout scenarios where clients attempt to check out both regular and credit-based licenses.
   * TC_Checkin: Verify licenses are correctly checked in under various conditions: explicit release by the client, job completion, client disconnection, and server shutdown.
   * TC_Upgrade: Verify the server correctly handles license upgrade requests (same license, higher seat count).
 * Story Points: 8
8. SALT-XXXX-8: Verify Proxy/Credit Server License Sharing
 * Description: Tests sharing with dup groups and vendor data. Verifies correct license sharing behavior.
 * Acceptance Criteria:
   * Correct UHDV and dup group NONE behavior.
   * Vendor data interaction.
 * Test Cases:
   * TC_Sharing_DupGroup: Verify the server correctly implements license sharing based on UHDV settings and dup groups, including ensuring that credit-based licenses are not shared unless specifically allowed.
   * TC_Sharing_VendorData: Verify the server correctly uses vendor data (if applicable) to further refine license sharing behavior, including ensuring that different vendor data values prevent sharing even if other criteria allow it.
 * Story Points: 5
9. SALT-XXXX-9: Verify Proxy/Credit Server Options File Functionality
 * Description: Tests options file (include/exclude). Verifies access control mechanisms.
 * Acceptance Criteria:
   * Include/exclude enforced.
   * Denial prevents credit activity.
 * Test Cases:
   * TC_Options_Lists: Verify the server correctly enforces include/exclude lists defined in the options file, granting or denying access to licenses based on


Sent from Gmail Mobile
