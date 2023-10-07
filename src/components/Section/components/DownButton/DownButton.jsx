/* eslint-disable jsx-a11y/label-has-associated-control */
import React from 'react';
import scrollTo from '../../../../utils/scrollTo';
import { ReactComponent as DownArrow } from './downarrow.svg';
import styles from './DownButton.module.scss';

const DownButton = ({ goToSectionRef }) => (
  <div
    className={styles.downArrow}
  >
    <label htmlFor="button">scroll</label>
    <button
      type="button"
      onClick={() => { scrollTo(goToSectionRef); }}
    >
      <DownArrow />
    </button>
  </div>
);

export default DownButton;
