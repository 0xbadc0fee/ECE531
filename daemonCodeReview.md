
# Table of Contents

1.  [Firmware Analysis Report](#orgd6c1ce4)
2.  [Abstract](#org2fd0541)
3.  [Target(s)](#orgaed34de)
    1.  [Sample 1](#org6642a48)
        1.  [name: mod4logd.c](#org6a5be5f)
        2.  [obtained as:](#org753b797)
        3.  [source language:](#org2e72166)
    2.  [Sample 2](#orgfb64211)
        1.  [name: S80sampled](#org8f180e1)
        2.  [obtained as:](#org33e905d)
        3.  [source language:](#org64533d6)
4.  [Methods](#org8e79263)
    1.  [Applicable Standards](#org88c36d5)
    2.  [Applicable Attack Vectors](#orgdfd997d)
    3.  [Suggested Tests, Manual](#org748fd51)
        1.  [Test Set: Sample 1](#orgba67547)
        2.  [Test Set: Sample 2](#orgf077ee1)
    4.  [Suggested Tests, Automatic (SAST)](#org61be84d)
5.  [Findings](#org6e16ff2)
    1.  [Results: Sample 1 Manual Review](#org47ac524)
    2.  [Results: Sample 1 SAST Scan results](#orgaeb5259)
    3.  [Results: Sample 2 Manual Review](#org8dbe17f)
    4.  [Results: Sample 2 Scan Results](#org20b7fa7)
6.  [Conclusion](#org2281fff)
    1.  [Attack Surface](#org8be453e)
        1.  [Data Paths](#org5ea6527)
        2.  [Data Path protections](#org680bad2)
        3.  [Valueable data](#org03e6e3a)
        4.  [Valueable data protections](#org3d789f2)



<a id="orgd6c1ce4"></a>

# Firmware Analysis Report

This report serves as a template for analyzing the attack surface of firmware samples.  Samples may


<a id="org2fd0541"></a>

# Abstract


<a id="orgaed34de"></a>

# Target(s)


<a id="org6642a48"></a>

## Sample 1


<a id="org6a5be5f"></a>

### name: mod4logd.c


<a id="org753b797"></a>

### obtained as:

-   [X] source code
-   [ ] compresed binary
-   [ ] encrypt


<a id="org2e72166"></a>

### source language:

-   [X] C, C++
-   [ ] PHP
-   [ ] SH
-   [ ] N/A


<a id="orgfb64211"></a>

## Sample 2


<a id="org8f180e1"></a>

### name: S80sampled


<a id="org33e905d"></a>

### obtained as:

-   [X] source code
-   [ ] compressed binary
-   [ ] encrypted
-   [ ] other


<a id="org64533d6"></a>

### source language:

-   [ ] C, C++
-   [ ] PHP
-   [X] SH
-   [ ] N/A


<a id="org8e79263"></a>

# Methods


<a id="org88c36d5"></a>

## Applicable Standards

-   [X] OWASP
-   [X] SANS
-   [ ] CERT
-   [ ] CVE
-   [X] MITRE / CWE / CWE Top 25
-   [ ] NVE
-   [ ] PA-DSS


<a id="orgdfd997d"></a>

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


<a id="org748fd51"></a>

## Suggested Tests, Manual


<a id="orgba67547"></a>

### Test Set: Sample 1

1.  Data / Input Validation

    -   [ ] CWE-665 Improper Initialization
    -   [ ] Stack Overflows
    -   [ ] Formatted Strings

2.  Session Management

3.  Authorization

    -   [X] CWE-732 Incorrect Permission Assignment

4.  Logging / Auditing


<a id="orgf077ee1"></a>

### Test Set: Sample 2

1.  Data / Input Validation

    -   [ ] CWE-665 Improper Initialization
    -   [ ] Stack Overflows
    -   [ ] Formatted Strings


<a id="org61be84d"></a>

## Suggested Tests, Automatic (SAST)

-   [X] CodeQL (GitHub)
-   [ ] SonarQube
-   [ ] Snyk
-   [ ] Veracode
-   [ ] AppScan
-   [ ] Checkmarx
-   [X] ShellCheck


<a id="org6e16ff2"></a>

# Findings


<a id="org47ac524"></a>

## Results: Sample 1 Manual Review

The code in Sample 1, mod4logd.c, is a very short program with limited scope. A
brief manual review of the code, after successfully compiling and running,
showed no obvious security vulnerabilities.  Special attention was paid to
variable declarations, variable initializations, data types, and string
formatting.  The program was then uploaded to github.com for use with the github
SAST tool 'codeql'.


<a id="orgaeb5259"></a>

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


<a id="org8dbe17f"></a>

## Results: Sample 2 Manual Review


<a id="org20b7fa7"></a>

## Results: Sample 2 Scan Results


<a id="org2281fff"></a>

# Conclusion

While the code for Sample 1 is quite small and presented no obvious security
vulnerabilities during the manual and automated testing; the process was very
useful in building the workflow you see here.  This work flow has become the
basis of a template for further code testing.


<a id="org8be453e"></a>

## Attack Surface

The attack surface for Sample 1 can be described as:


<a id="org5ea6527"></a>

### Data Paths

1.  Argument strings

    -   This program relies on properly formated string arguments provided by the
        user.

2.  Libraries

3.  Data ingest

4.  Data export


<a id="org680bad2"></a>

### Data Path protections

1.  Authentication

2.  Authorization

3.  Activity Logging

4.  Data Validation


<a id="org03e6e3a"></a>

### Valueable data

1.  Secrets & Keys

2.  Intellectual Property

3.  Critical Business Data

4.  Personal or PII data


<a id="org3d789f2"></a>

### Valueable data protections

1.  encryption & checksums

2.  access auditing

3.  data integrity

4.  operational security controls

