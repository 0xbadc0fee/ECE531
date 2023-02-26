
# Table of Contents

1.  [Firmware Analysis Report](#org1582ca9)
2.  [Abstract](#org8b2672e)
3.  [Target(s)](#orgb206665)
    1.  [Sample 1](#orgcfd24cb)
        1.  [name:](#orge5267d9)
        2.  [obtained as:](#org36d6d0e)
        3.  [source language:](#org8ca3299)
    2.  [Sample 2](#org0b67a54)
        1.  [name:](#org3230be5)
        2.  [obtained as:](#org7845db1)
        3.  [source language:](#orgead9311)
4.  [Methods](#org100bad2)
    1.  [Applicable Standards](#org383b0e8)
    2.  [Applicable Attack Vectors](#orga53cf42)
    3.  [Suggested Test Sets](#orga874cde)
        1.  [Test Set: Sample 1](#orga1f55f2)
        2.  [Test Set: Sample 2](#org8ef50f3)
5.  [Findings](#org7e928b0)
6.  [Conclusion](#orgacf3ca8)



<a id="org1582ca9"></a>

# Firmware Analysis Report

This report serves as a template for analyzing the attack surface of firmware samples.  Samples may


<a id="org8b2672e"></a>

# Abstract


<a id="orgb206665"></a>

# Target(s)


<a id="orgcfd24cb"></a>

## Sample 1


<a id="orge5267d9"></a>

### name:


<a id="org36d6d0e"></a>

### obtained as:

-   source code
-   compresed binary
-   encrypted
-   other


<a id="org8ca3299"></a>

### source language:

-   C, C++
-   PHP
-   SH
-   N/A


<a id="org0b67a54"></a>

## Sample 2


<a id="org3230be5"></a>

### name:


<a id="org7845db1"></a>

### obtained as:

-   source code
-   compressed binary
-   encrypted
-   other


<a id="orgead9311"></a>

### source language:

-   C, C++
-   PHP
-   SH
-   N/A


<a id="org100bad2"></a>

# Methods


<a id="org383b0e8"></a>

## Applicable Standards

-   [X] OWASP
-   [X] SANS
-   [ ] CERT
-   [ ] CVE
-   [X] MITRE / CWE / CWE Top 25
-   [ ] NVE
-   [ ] PA-DSS


<a id="orga53cf42"></a>

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


<a id="orga874cde"></a>

## Suggested Test Sets


<a id="orga1f55f2"></a>

### Test Set: Sample 1

1.  Data / Input Validation

    -   [ ] CWE-665 Improper Initialization
    -   [ ] Stack Overflows
    -   [ ] Formatted Strings

2.  Session Management

3.  Authorization

    -   [X] CWE-732 Incorrect Permission Assignment

4.  Logging / Auditing


<a id="org8ef50f3"></a>

### Test Set: Sample 2


<a id="org7e928b0"></a>

# Findings


<a id="orgacf3ca8"></a>

# Conclusion

