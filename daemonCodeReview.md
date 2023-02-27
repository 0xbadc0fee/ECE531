
# Table of Contents

1.  [Firmware Analysis Report](#orgf6d13fd)
2.  [Abstract](#org5b6afac)
3.  [Target(s)](#org5f6b8a3)
    1.  [Sample 1](#orgb6e2820)
        1.  [name: mod4logd.c](#org02e4c18)
        2.  [obtained as:](#org24dcff0)
        3.  [source language:](#org5dcc968)
    2.  [Sample 2](#org0f621aa)
        1.  [name: S80sampled](#org03f9ca9)
        2.  [obtained as:](#orgf0838f1)
        3.  [source language:](#org7d8d90d)
4.  [Methods](#org1598c44)
    1.  [Applicable Standards](#orgb07c4ef)
    2.  [Applicable Attack Vectors](#orgc5f1c32)
    3.  [Suggested Tests, Manual](#org30b23b5)
        1.  [Test Set: Sample 1](#orga5551e3)
        2.  [Test Set: Sample 2](#org9f39885)
    4.  [Suggested Tests, Automatic (SAST)](#org44528e2)
5.  [Findings](#orgb7db248)
    1.  [Results: Sample 1 Manual Review](#org9f9b74b)
    2.  [Results: Sample 1 SAST Scan results](#org637ed72)
    3.  [Results: Sample 2 Manual Review](#org1bcb75b)
    4.  [Results: Sample 2 Scan Results](#org19ce603)
6.  [Conclusion](#org7bec7d8)
    1.  [Attack Surface](#org2b337b9)
        1.  [Data Paths](#orga5d9a10)
        2.  [Data Path protections](#org3c3f614)
        3.  [Valueable data](#orgeadc407)
        4.  [Valueable data protections](#orgf8212b2)



<a id="orgf6d13fd"></a>

# Firmware Analysis Report

This report serves as a template for analyzing the attack surface of firmware samples.  Samples may


<a id="org5b6afac"></a>

# Abstract


<a id="org5f6b8a3"></a>

# Target(s)


<a id="orgb6e2820"></a>

## Sample 1


<a id="org02e4c18"></a>

### name: mod4logd.c


<a id="org24dcff0"></a>

### obtained as:

-   [X] source code
-   [ ] compresed binary
-   [ ] encrypt


<a id="org5dcc968"></a>

### source language:

-   [X] C, C++
-   [ ] PHP
-   [ ] SH
-   [ ] N/A


<a id="org0f621aa"></a>

## Sample 2


<a id="org03f9ca9"></a>

### name: S80sampled


<a id="orgf0838f1"></a>

### obtained as:

-   [X] source code
-   [ ] compressed binary
-   [ ] encrypted
-   [ ] other


<a id="org7d8d90d"></a>

### source language:

-   [ ] C, C++
-   [ ] PHP
-   [X] SH
-   [ ] N/A


<a id="org1598c44"></a>

# Methods


<a id="orgb07c4ef"></a>

## Applicable Standards

-   [X] OWASP
-   [X] SANS
-   [ ] CERT
-   [ ] CVE
-   [X] MITRE / CWE / CWE Top 25
-   [ ] NVE
-   [ ] PA-DSS


<a id="orgc5f1c32"></a>

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


<a id="org30b23b5"></a>

## Suggested Tests, Manual


<a id="orga5551e3"></a>

### Test Set: Sample 1

1.  Data / Input Validation

    -   [ ] CWE-665 Improper Initialization
    -   [ ] Stack Overflows
    -   [ ] Formatted Strings

2.  Session Management

3.  Authorization

    -   [X] CWE-732 Incorrect Permission Assignment

4.  Logging / Auditing


<a id="org9f39885"></a>

### Test Set: Sample 2

1.  Data / Input Validation

    -   [ ] CWE-665 Improper Initialization
    -   [ ] Stack Overflows
    -   [ ] Formatted Strings


<a id="org44528e2"></a>

## Suggested Tests, Automatic (SAST)

-   [X] CodeQL (GitHub)
-   [ ] SonarQube
-   [ ] Snyk
-   [ ] Veracode
-   [ ] AppScan
-   [ ] Checkmarx
-   [X] ShellCheck


<a id="orgb7db248"></a>

# Findings


<a id="org9f9b74b"></a>

## Results: Sample 1 Manual Review

The code in Sample 1, mod4logd.c, is a very short program with limited scope. A
brief manual review of the code, after successfully compiling and running,
showed no obvious security vulnerabilities.  Special attention was paid to
variable declarations, variable initializations, data types, and string
formatting.  The program was then uploaded to github.com for use with the github
SAST tool 'codeql'.


<a id="org637ed72"></a>

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


<a id="org1bcb75b"></a>

## Results: Sample 2 Manual Review

A manual review of the daemon shell S80sampled did not produce any obvious
vulnerabilities. 


<a id="org19ce603"></a>

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


<a id="org7bec7d8"></a>

# Conclusion

While the code for Sample 1 is quite small and presented no obvious security
vulnerabilities during the manual and automated testing; the process was very
useful in building the workflow you see here.  This work flow has become the
basis of a template for further code testing.


<a id="org2b337b9"></a>

## Attack Surface

The attack surface for Sample 1 can be described as:


<a id="orga5d9a10"></a>

### Data Paths

1.  Argument strings

    -   This program relies on properly formated string arguments provided by the
        user.

2.  Libraries

3.  Data ingest

4.  Data export


<a id="org3c3f614"></a>

### Data Path protections

1.  Authentication

2.  Authorization

3.  Activity Logging

4.  Data Validation


<a id="orgeadc407"></a>

### Valueable data

1.  Secrets & Keys

2.  Intellectual Property

3.  Critical Business Data

4.  Personal or PII data


<a id="orgf8212b2"></a>

### Valueable data protections

1.  encryption & checksums

2.  access auditing

3.  data integrity

4.  operational security controls

