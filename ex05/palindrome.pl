#!/usr/bin/perl

use strict;
use warnings;

print "Enter a string: ";
my $word = lc <STDIN>;
chomp $word;

if ($word eq reverse $word) {
    print "The string is a palindrome.\n";
} else {
    print "The string is not a palindrome.\n";
}
