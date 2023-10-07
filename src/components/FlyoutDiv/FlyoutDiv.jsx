import React from 'react';
import styles from './FlyoutDiv.module.scss';

const FlyoutDiv = () => (
  <div>
    <div className={styles.container}>
      <div className={styles.cardGroup}>
        <div className={`${styles.card} ${styles.littleCard}`} />
        <div className={`${styles.card} ${styles.bigCard}`} />
        <div className={`${styles.card} ${styles.littleCard}`} />
        <div className={`${styles.card} ${styles.bigCard}`} />
        <div className={`${styles.card} ${styles.littleCard}`} />
        <div className={`${styles.card} ${styles.bigCard}`} />
        <div className={`${styles.card} ${styles.littleCard}`} />
        <div className={`${styles.card} ${styles.bigCard}`} />
      </div>
    </div>
  </div>
);

export default FlyoutDiv;
