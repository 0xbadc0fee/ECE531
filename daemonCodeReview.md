
# Table of Contents

1.  [Firmware Analysis Report](#orgaf1a800)
2.  [Abstract](#org0c56b64)
3.  [Target(s)](#orgdb2faf8)
    1.  [Sample 1](#org80c8322)
        1.  [name: mod4logd.c](#org2705ecf)
        2.  [obtained as:](#org4d22696)
        3.  [source language:](#org70bd84a)
    2.  [Sample 2](#orgafcf2bf)
        1.  [name: S80sampled](#org15a30e4)
        2.  [obtained as:](#org8e154fa)
        3.  [source language:](#org56c2c58)
4.  [Methods](#org94c4c3f)
    1.  [Applicable Standards](#org92b281d)
    2.  [Applicable Attack Vectors](#org3c25b1a)
    3.  [Suggested Tests, Manual](#orge1a1c6a)
        1.  [Test Set: Sample 1](#orgef18fdb)
        2.  [Test Set: Sample 2](#orgd488761)
    4.  [Suggested Tests, Automatic (SAST)](#org9b4a7e9)
5.  [Findings](#org37ec047)
    1.  [Results: Sample 1 Manual Review](#org51f093c)
    2.  [Results: Sample 1 SAST Scan results](#org95b47ab)
    3.  [Results: Sample 2 Manual Review](#orged9e424)
    4.  [Results: Sample 2 Scan Results](#org45ae079)
6.  [Conclusion](#orga555885)
    1.  [Attack Surface](#org4eb2d54)
        1.  [Data Paths](#orga3d68fb)
        2.  [Data Path protections](#org904e15d)
        3.  [Valueable data](#org3160654)
        4.  [Valueable data protections](#orgb92508c)



<a id="orgaf1a800"></a>

# Firmware Analysis Report

This report serves as a template for analyzing the attack surface of firmware samples.  Samples may


<a id="org0c56b64"></a>

# Abstract


<a id="orgdb2faf8"></a>

# Target(s)


<a id="org80c8322"></a>

## Sample 1


<a id="org2705ecf"></a>

### name: mod4logd.c


<a id="org4d22696"></a>

### obtained as:

-   [X] source code
-   [ ] compresed binary
-   [ ] encrypt


<a id="org70bd84a"></a>

### source language:

-   [X] C, C++
-   [ ] PHP
-   [ ] SH
-   [ ] N/A


<a id="orgafcf2bf"></a>

## Sample 2


<a id="org15a30e4"></a>

### name: S80sampled


<a id="org8e154fa"></a>

### obtained as:

-   [X] source code
-   [ ] compressed binary
-   [ ] encrypted
-   [ ] other


<a id="org56c2c58"></a>

### source language:

-   [ ] C, C++
-   [ ] PHP
-   [X] SH
-   [ ] N/A


<a id="org94c4c3f"></a>

# Methods


<a id="org92b281d"></a>

## Applicable Standards

-   [X] OWASP
-   [X] SANS
-   [ ] CERT
-   [ ] CVE
-   [X] MITRE / CWE / CWE Top 25
-   [ ] NVE
-   [ ] PA-DSS


<a id="org3c25b1a"></a>

## Applicable Attack Vectors

-   [X] Data / Input Validation
-   [X] Authentication
-   [ ] Session Management
-   [ ] Authorization
-   [ ] Cryptography
-   [ ] Error Handling
-   [X] Logging / Auditing
-   [ ] Secure Code Environment
-   [X] Bad Coding Practices


<a id="orge1a1c6a"></a>

## Suggested Tests, Manual


<a id="orgef18fdb"></a>

### Test Set: Sample 1

1.  Data / Input Validation

    -   [ ] CWE-665 Improper Initialization
    -   [ ] Stack Overflows
    -   [ ] Formatted Strings

2.  Session Management

3.  Authorization

    -   [X] CWE-732 Incorrect Permission Assignment

4.  Logging / Auditing


<a id="orgd488761"></a>

### Test Set: Sample 2

1.  Data / Input Validation

    -   [ ] CWE-665 Improper Initialization
    -   [ ] Stack Overflows
    -   [ ] Formatted Strings


<a id="org9b4a7e9"></a>

## Suggested Tests, Automatic (SAST)

-   [X] CodeQL (GitHub)
-   [ ] SonarQube
-   [ ] Snyk
-   [ ] Veracode
-   [ ] AppScan
-   [ ] Checkmarx
-   [X] ShellCheck


<a id="org37ec047"></a>

# Findings


<a id="org51f093c"></a>

## Results: Sample 1 Manual Review

The code in Sample 1, mod4logd.c, is a very short program with limited scope. A
brief manual review of the code, after successfully compiling and running,
showed no obvious security vulnerabilities.  Special attention was paid to
variable declarations, variable initializations, data types, and string
formatting.  The program was then uploaded to github.com for use with the github
SAST tool 'codeql'.


<a id="org95b47ab"></a>

## Results: Sample 1 SAST Scan results

Before the code in Sample 1 could be scanned with CodeQL, a special YAML file
needed to be configured for the mod4logd.c code.  A 'dry' run was configured
first in which no security scanning was done; but would confirm that CodeQL
could compile and run the binary produced by internally compiling the c code.
The configuration was set for an Ubuntu 20.04 environment, assigned the
necessary libraries, and instructed to run 'make' in the same manner as was done
on the development box.

After making a few edits to the YAML file to succesfully compile the c code, the
testing queries 'security-and-quality' and 'security-extended' were added to the
YAML file instructions.  The code was then scanned again with the targeted
security queries.

The results came back with no alerts or warnings.  Just to confirm the code
scanner was working as intended, a deliberate vulnerability was then added to
mod4logd.c in the form of an unitialized variable that was then called in a
function named '<sub>do</sub><sub>badidea</sub>'.  On the development box the unitialized variable
caused no problem in compiling or running the function.  The modified program
was then pushed to the same github repository and an automatic re-scan was then
triggered for CodeQL.  The second round of CodeQL scanning correctly identified
the unitialized variable as a security vulnerability and logged an alert.
Having confirmed the scanner was functioning, the deliberate flaw was removed
and the code recomitted to the original repository.


<a id="orged9e424"></a>

## Results: Sample 2 Manual Review

A manual review of the daemon shell S80sampled did not produce any obvious
vulnerabilities. 


<a id="org45ae079"></a>

## Results: Sample 2 Scan Results

An automated scan of the script S80sampled produced alerts on the use of
variables when calling 'printf()'

    In S80sampled line 6:
      printf "Starting $DAEMON_NAME: "
             ^-----------------------^ SC2059: Don't use variables in the printf... 
    format string. Use printf "..%s.." "$foo".
    
    In S80sampled line 13:
      printf "Stopping $DAEMON_NAME: "
             ^-----------------------^ SC2059: Don't use variables in the printf...
    format string. Use printf "..%s.." "$foo".
    
    For more information:
      https://www.shellcheck.net/wiki/SC2059 -- Don't use variables in the printf...

After making the suggested edits at lines 6 & 13, the shell script was rescanned
and the results produced no errors or alerts.


<a id="orga555885"></a>

# Conclusion

While the code for Sample 1 is quite small and presented no obvious security
vulnerabilities during the manual and automated testing; the process was very
useful in building the workflow you see here.  This work flow has become the
basis of a template for further code testing.


<a id="org4eb2d54"></a>

## Attack Surface

The attack surface for Sample 2 can be described as:


<a id="orga3d68fb"></a>

### Data Paths

1.  Argument strings

    -   This program relies on properly formated string arguments provided by the
        user.  This could possibly be exploited. CWE-135

2.  Libraries

    -   n/a

3.  Data ingest

    -   n/a

4.  Data export

    -   n/a


<a id="org904e15d"></a>

### Data Path protections

1.  Authentication

    -   There is no explicit user authentication built into this script. CWE-287

2.  Authorization

    -   There is no explicit user authorization built into this script. CWE-285

3.  Activity Logging

    -   There is no activity logging built into this script. CWE-778, OWASP top 10.

4.  Data Validation

    -   n/a


<a id="org3160654"></a>

### Valueable data

1.  Secrets & Keys

    -   n/a

2.  Intellectual Property

    -   n/a

3.  Critical Business Data

    -   n/a

4.  Personal or PII data

    -   n/a


<a id="orgb92508c"></a>

### Valueable data protections

1.  encryption & checksums

    -   n/a

2.  access auditing

    -   n/a

3.  data integrity

    -   n/a

4.  operational security controls

    -   n/a

