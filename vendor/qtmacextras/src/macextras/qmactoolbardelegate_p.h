/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtMacExtras module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QMACTOOLBARDELEGATE_H
#define QMACTOOLBARDELEGATE_H

#import <AppKit/AppKit.h>
#include "qmactoolbutton.h"
//#include <QString>
//#include <QHash>

#include <qglobal.h>
#include <private/qcore_mac_p.h>

#include <QAction>
#include <QIcon>
#if defined( __OBJC__) && defined(QT_NAMESPACE)
  #define QT_NAMESPACE_ALIAS_OBJC_CLASS(__KLASS__) @compatibility_alias __KLASS__ QT_MANGLE_NAMESPACE(__KLASS__)
#else
   #define QT_NAMESPACE_ALIAS_OBJC_CLASS(__KLASS__)
#endif

@interface QT_MANGLE_NAMESPACE(QMacToolbarDelegate) : NSObject <NSToolbarDelegate>
{
@public
    QList<QMacToolButton *> items;
    QList<QMacToolButton *> allowedItems;

//    QHash<QString, QAction*> actions;
//    QHash<QString, QAction*> allowedActions;
}

- (NSToolbarItem *) toolbar: (NSToolbar *)toolbar itemForItemIdentifier: (NSString *) itemIdent willBeInsertedIntoToolbar:(BOOL) willBeInserted;
- (NSArray *)toolbarDefaultItemIdentifiers:(NSToolbar*)toolbar;
- (NSArray *)toolbarAllowedItemIdentifiers:(NSToolbar*)toolbar;
- (NSArray *)toolbarSelectableItemIdentifiers:(NSToolbar *)toolbar;

- (QAction *)addActionWithText:(const QString *)text;
- (QAction *)addActionWithText:(const QString *)text icon:(const QIcon *)icon;
- (QAction *)addAction:(QAction *)action;
- (QAction *)addStandardItem:(QMacToolButton::StandardItem)standardItem;

- (QAction *)addAllowedActionWithText:(const QString *)text;
- (QAction *)addAllowedActionWithText:(const QString *)text icon:(const QIcon *)icon;
- (QAction *)addAllowedAction:(QAction *)action;
- (QAction *)addAllowedStandardItem:(QMacToolButton::StandardItem)standardItem;

- (IBAction)itemClicked:(id)sender;
@end

QT_NAMESPACE_ALIAS_OBJC_CLASS(QMacToolbarDelegate);

#endif // QMACTOOLBARDELEGATE_H
