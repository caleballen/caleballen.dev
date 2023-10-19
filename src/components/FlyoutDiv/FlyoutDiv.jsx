import React from 'react';
import styles from './FlyoutDiv.module.scss';

const FlyoutDiv = ({ children }) => {
  if (children?.length !== 8) {
    throw new Error('FlyoutDiv has incorrect amount of children');
  }

  return (
    <div className={styles.container}>
      <div className={styles.cardGroup}>
        <div className={`${styles.card} ${styles.littleCard}`}>{children[0]}</div>
        <div className={`${styles.card} ${styles.bigCard}`}>{children[1]}</div>
        <div className={`${styles.card} ${styles.littleCard}`}>{children[2]}</div>
        <div className={`${styles.card} ${styles.bigCard}`}>{children[3]}</div>
        <div className={`${styles.card} ${styles.littleCard}`}>{children[4]}</div>
        <div className={`${styles.card} ${styles.bigCard}`}>{children[5]}</div>
        <div className={`${styles.card} ${styles.littleCard}`}>{children[6]}</div>
        <div className={`${styles.card} ${styles.bigCard}`}>{children[7]}</div>
      </div>
    </div>
  );
};

export default FlyoutDiv;
