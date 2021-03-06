/**
 * @file tools/cathedral/src/ActionUpdateLNCUI.cpp
 * @ingroup cathedral
 *
 * @author COMP Omega <compomega@tutanota.com>
 *
 * @brief Implementation for an update LNC action.
 *
 * Copyright (C) 2012-2020 COMP_hack Team <compomega@tutanota.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ActionUpdateLNCUI.h"

// Cathedral Includes
#include "MainWindow.h"

// Ignore warnings
#include <PushIgnore.h>

// Qt Includes
#include <QLineEdit>

#include "ui_Action.h"
#include "ui_ActionUpdateLNC.h"

// Stop ignoring warnings
#include <PopIgnore.h>

// libcomp Includes
#include <Log.h>
#include <PacketCodes.h>

ActionUpdateLNC::ActionUpdateLNC(ActionList *pList, MainWindow *pMainWindow,
                                 QWidget *pParent)
    : Action(pList, pMainWindow, pParent) {
  QWidget *pWidget = new QWidget;
  prop = new Ui::ActionUpdateLNC;
  prop->setupUi(pWidget);

  ui->actionTitle->setText(tr("<b>Update LNC</b>"));
  ui->layoutMain->addWidget(pWidget);
}

ActionUpdateLNC::~ActionUpdateLNC() { delete prop; }

void ActionUpdateLNC::Load(const std::shared_ptr<objects::Action> &act) {
  mAction = std::dynamic_pointer_cast<objects::ActionUpdateLNC>(act);

  if (!mAction) {
    return;
  }

  LoadBaseProperties(mAction);

  prop->value->setValue(mAction->GetValue());
  prop->isSet->setChecked(mAction->GetIsSet());
}

std::shared_ptr<objects::Action> ActionUpdateLNC::Save() const {
  if (!mAction) {
    return nullptr;
  }

  SaveBaseProperties(mAction);

  mAction->SetValue((int16_t)prop->value->value());
  mAction->SetIsSet(prop->isSet->isChecked());

  return mAction;
}
