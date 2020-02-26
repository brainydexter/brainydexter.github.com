#! /bin/sh
#############################################################################
##
## Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
## All rights reserved.
## Contact: Nokia Corporation (qt-info@nokia.com)
##
## This file is the build configuration utility of the Qt Toolkit.
##
## $QT_BEGIN_LICENSE:LGPL$
## Commercial Usage
## Licensees holding valid Qt Commercial licenses may use this file in
## accordance with the Qt Commercial License Agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and Nokia.
##
## GNU Lesser General Public License Usage
## Alternatively, this file may be used under the terms of the GNU Lesser
## General Public License version 2.1 as published by the Free Software
## Foundation and appearing in the file LICENSE.LGPL included in the
## packaging of this file.  Please review the following information to
## ensure the GNU Lesser General Public License version 2.1 requirements
## will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
##
## In addition, as a special exception, Nokia gives you certain additional
## rights.  These rights are described in the Nokia Qt LGPL Exception
## version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
##
## GNU General Public License Usage
## Alternatively, this file may be used under the terms of the GNU
## General Public License version 3.0 as published by the Free Software
## Foundation and appearing in the file LICENSE.GPL included in the
## packaging of this file.  Please review the following information to
## ensure the GNU General Public License version 3.0 requirements will be
## met: http://www.gnu.org/copyleft/gpl.html.
##
## If you have questions regarding the use of this file, please contact
## Nokia at qt-info@nokia.com.
## $QT_END_LICENSE$
##
#############################################################################

# Compile a .glsl file to a file that can be included in a C++ program
USAGE="Usage: $0 <file.glsl>"
CGC=cgc
CGC_PROFILE=arbfp1

if test $# -ne 1
then
    echo $USAGE
    exit 1
fi

GLSL_FILE=$1
FRAG_FILE=`basename $1 .glsl`.frag
#GLSL_INC_FILE=`basename $1 .glsl`.glsl_quoted

echo "// Generated by src/opengl/util/$0 from $1" > $FRAG_FILE
$CGC -quiet -oglsl -profile $CGC_PROFILE $GLSL_FILE | while read line
do
   if test `echo $line | cut -c1` != "#"
   then
      echo -e \"$line\" >> $FRAG_FILE
   fi
done
echo "; // Generated by src/opengl/util/$0 from $1" >> $FRAG_FILE

#echo "// Generated by src/opengl/util/$0 from $1" > $GLSL_INC_FILE
#cat $GLSL_FILE | while read line
#do
#      printf \"%s\\\\n\"\\n "$line" >> $GLSL_INC_FILE
#done
#echo "; // Generated by src/opengl/util/$0 from $1" >> $GLSL_INC_FILE